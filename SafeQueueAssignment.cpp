// producer-consumer example using a monitor.

// g++ -pthread -fsanitize=thread -g SafeQueueAssignment.cpp

#include <fstream>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <string>

// returns the nth fibonacci value
// the recursive solution is prettier, but too slow.
uint64_t fibonacci(int n)
{
  if (n == 0 ) {
    return n;
  }
  if (n == 1) {
    return n;
  }

  uint64_t n0, n1;
  int i;
  n0 = 1;
  n1 = 1;

  for(i = 2; i < n; i++) {
    uint64_t t;
    t = n1;
    n1 = t + n0;
    n0 = t;
  }
  return n1 + n0;
}

// FIFO Queue using a linked list (singly) monitor class
// values are inserted at the front and removed at the rear
class SafeQueue {

private:
    pthread_mutex_t lock;
    // semaphore to keep track of the number of items in the queue
    sem_t queue_count;

public:
    struct node {
        uint64_t data;
        node *next;
    };

    node *head;

    // need a mutex and semaphore initialization whenever a queue is created?
    SafeQueue()
    {
      pthread_mutex_init(&lock, NULL);
      sem_init(&queue_count, 1, 0);
      this->head = NULL;
    }

    SafeQueue(uint64_t value)
    {
      pthread_mutex_init(&lock, NULL);
      sem_init(&queue_count, 1, 0);
      this->head->data = value;
      this->head->next = NULL;
    }

    // do we need a destructor for the mutex & semaphore?
    ~SafeQueue()
    {
      pthread_mutex_destroy(&lock);
      sem_destroy(&queue_count);
    }

    // FIFO queue: all inserted values to front.
    void Write(uint64_t value)
    {
      // enter CS
      pthread_mutex_lock(&lock);

      // add value to queue
      node* newNode = new node;
      newNode->data = value;
      newNode->next = head;
      head = newNode;

      // increment semaphore
      sem_post(&queue_count);

      // leave CS
      pthread_mutex_unlock(&lock);
    }

    // functionality check
    void traverse()
    {
      if (isEmpty()) {
          std::cout << "Empty list." << std::endl;
          return;
      }
      node* travelNode = head;
      while(travelNode) {
          std::cout << travelNode->data << " -> ";
          travelNode = travelNode->next;
      }
      std::cout << std::endl;
    }

    // true if empty
    bool isEmpty() {
        return head == NULL;
    }

    // traverses the list and returns the value stored in the last node
    uint64_t Dequeue()
    {
      // should probably check if the queue is empty, however, it will (shouldn't)
      // be accessed in this implemention w/o calling the read function first
      // which will block if the semaphore == 0 (which means the queue is
      // empty)

      if (this->isEmpty()) {
        // implement something, perhaps
        return -1;
      }

      // if only one value in the list
      if (head->next == NULL) {
          uint64_t retVal = head->data;
          head = NULL;
          return retVal;
      }

      // more than one value in the list
      // traverse the list and return the value stored in the last node
      else {
      node* temp = head;
      while(temp->next->next){
          temp = temp->next;
      }
      uint64_t retVal = temp->next->data;
      temp->next = NULL;

      return retVal;
      }
    }

    // reads value from queue. Blocks if queue is empty.
    void Read(uint64_t &value)
    {
      // sem_wait should block if the semaphore is currently 0
      // there shouldnt be a need to implement a check otherwise?
      // see man sem_wait for elaboration

      // decrement semaphore
      sem_wait(&queue_count);
      // enter CS
      pthread_mutex_lock(&lock);

      // read value and remove from queue
      value = Dequeue();

      // if we're here, something has failed.
      if (value == -1) {
        std::cout << "Something is broken.\n";
        exit(0);
      }

      // leave CS
      pthread_mutex_unlock(&lock);
    }
};

// for passing both parameters to the thread functions
typedef struct {
  SafeQueue s;
  int n;
} QueueType;


void *Calculate(void *parameter)
{
  // cast the pointer; use the QT's n value (user entered value)
  // as the top of the loop's range
  QueueType *QT = (QueueType *) parameter;
  for(int i = 0; i < QT->n; i++)
  {
    QT->s.Write(fibonacci(i));
  }
  pthread_exit(0);
}

void *Printing(void *parameter)
{
  std::ofstream outFile;
  QueueType *QT = (QueueType *) parameter;
  FILE *fp;
  std::string fName = "Fib-";
  uint64_t fibVal;

  // generate filename by converting nvalue to
  // string, and appending appropriately

  std::string nStr = std::to_string(QT->n);
  fName = fName + nStr + ".txt";
  outFile.open(fName);

  for(int i = 0; i < QT->n; i++)
  {
    QT->s.Read(fibVal);
    outFile << fibVal << std::endl;
  }
  outFile.close();
  pthread_exit(0);
}


int main()
{
  // struct for parameter passing to the thread functions
  QueueType NewSQ;
  NewSQ.s = SafeQueue();

  // two additional threads: calc thread calculates each fib value and sends to
  // write
  // print thread reads each value from the queue and writes to a file

  pthread_t CalcThread, PrintThread;
  pthread_attr_t attr;

  bool validIn = false;

  pthread_attr_init(&attr);

  do {
    std::cout << "Enter val: ";
    std::cin >> NewSQ.n;

    if (NewSQ.n == -1) {
      std::cout << "Goodbye.\n";
      exit(0);
    }

    if (NewSQ.n > 50 || NewSQ.n == 0) {
      std::cout << "Please enter a value between 1-50\n";
      validIn = false;
    }

    else {
      validIn = true;
    }
  } while(!validIn);

  pthread_create(&CalcThread, &attr, Calculate, &NewSQ);
  pthread_create(&PrintThread, &attr, Printing, &NewSQ);


  pthread_join(CalcThread, NULL);
  pthread_join(PrintThread, NULL);

}
