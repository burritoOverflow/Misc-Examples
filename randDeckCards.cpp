// Simple representation of a deck of cards, a random shuffle of the deck, followed by drawing two random cards.

#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// where appropriate, convert value to corresponding char, eg. 1 == 'A', 11 == 'Jack', 12 == 'Queen' 13 == 'King'
void display_card_value(int val)
{
  std::map<int, std::string> card_val;
  card_val[1] = "Ace";
  card_val[11] = "Jack";
  card_val[12] = "Queen";
  card_val[13] = "King";

  std::map<int, std::string>::iterator it = card_val.find(val);
  // if the value is found, it will not == end
  if (it != card_val.end())
  {
    std::cout << card_val[val];
  }
  else
  {
    std::cout << val;
  }
}

// we need to assert the following: 1. Integer is between 1 and 13 (both inclusive), 2. String is either "Hearts", "Spades", "Clubs", "Diamonds"
void create_deck_suit(std::string suit, std::vector<std::pair<int, std::string>> &vec_deck)
{
  std::pair<int, std::string> card_pair;
  std::vector<std::pair<int, std::string>>::iterator it;

  for (int i = 1; i <= 13; i++)
  {
    card_pair = std::make_pair(i, suit);
    vec_deck.push_back(card_pair);
  }

  for (it = vec_deck.begin(); it != vec_deck.end(); ++it)
  {
    display_card_value(it->first);
    std::cout << " " << it->second << std::endl;
  }
}

void make_full_deck(std::vector<std::pair<int, std::string>> &vec_deck)
{
  std::string suit_array[4] = {"Diamonds", "Spades", "Hearts", "Clubs"};

  for (int i = 0; i < 4; i++)
  {
    create_deck_suit(suit_array[i], vec_deck);
  }
  // shuffle the deck for good measure. (Yes, i know we're drawing random cards)
  std::random_shuffle(vec_deck.begin(), vec_deck.end());
  printf("We have a full deck of %lu cards.\n", vec_deck.size());
}

// really, these cards should be removed from the deck and pushed back in, but that's for another time
std::pair<std::pair<int, std::string>, std::pair<int, std::string>> draw_two_cards(std::vector<std::pair<int, std::string>> &vec_deck)
{
  srand(time(NULL));

  int rand1, rand2;
  rand1 = rand() % 52 - 1;
  rand2 = rand() % 52 - 1;

  // this needs to be performed better, but a stupid dup check
  // also doesnt take into account this occuring twice. This is a temporary band-aid.
  if (rand1 == rand2)
  {
    printf("Wow, they we're actually the same! We're not supposed to be here!\n");
    rand2 = rand() % 52 - 1;
  }

  // return a pair of the two cards corresponding to the indicies found
  return std::make_pair(vec_deck[rand1], vec_deck[rand2]);
}

// this should display the contents of a pair of pairs(int, std::string)
void parse_pair(std::pair<std::pair<int, std::string>, std::pair<int, std::string>> ex_pair)
{
  std::pair<int, std::string> pair_1, pair_2;
  pair_1 = std::get<0>(ex_pair);
  pair_2 = std::get<1>(ex_pair);

  std::cout << pair_1.first << " of " << pair_1.second << std::endl;
  std::cout << pair_2.first << " of " << pair_2.second << std::endl;
}


int main()
{

  std::vector<std::pair<int,std::string> > deck;
  // now we've got the hearts taken care of
  make_full_deck(deck);

  std::pair<std::pair<int, std::string>, std::pair<int, std::string>> rand_cards;
  rand_cards = draw_two_cards(deck);

  parse_pair(rand_cards);

}
