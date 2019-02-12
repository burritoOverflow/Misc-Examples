# generates a random password using (hopefully) acceptable ASCII chars
# test generates 5 random passwords with a random length between 16-23 chars.

import random

def generate_rand_pw(length = random.randint(16, 24)):
    pw = ""
    for i in range(0, random.randint(16, 24)):
        pw = pw + chr(random.randint(33, 126))
    return pw

for i in range(0, 5):
    rand_pw = generate_rand_pw()
    print("Password is ", rand_pw, "a(n)", len(rand_pw), "char password.")

