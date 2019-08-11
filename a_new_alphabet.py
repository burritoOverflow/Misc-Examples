import unittest

def translate_new_alphabet(input_str):
    '''
        Performs the string translation.
        Takes the input string and returns the transformed string.
    '''
    output_str = ''
    for character in input_str:
        try:
            output_str += translation_dict[character.lower()]
        except KeyError:
            output_str += str(character)
    return output_str


translation_dict = {
  'a': '@',
  'b': '8',
  'c': '(',
  'd': '|)',
  'e': '3',
  'f': '#',
  'g': '6',
  'h': '[-]',
  'i': '|',
  'j': '_|',
  'k': '|<',
  'l': '1',
  'm': '''[]\/[]''',
  'n': '''[]\[]''',
  'o': '0',
  'p': '|D',
  'q': '(,)',
  'r': '|Z',
  's': '$',
  't': '''\'][\'''',
  'u': '|_|',
  'v': '''\/''',
  'w': '''\/\/''',
  'x': '}{',
  'y': '`/',
  'z': '2'
}

input_str = input()
print(translate_new_alphabet(input_str))


#
# test1 = translate_new_alphabet('All your base are belong to us.')
# assert test1 == '''@11 `/0|_||Z 8@$3 @|Z3 8310[]\[]6 ']['0 |_|$.'''
#
# test2 = translate_new_alphabet('''What's the Frequency, Kenneth?''')
# assert test2 == '''\/\/[-]@'][''$ ']['[-]3 #|Z3(,)|_|3[]\[](`/, |<3[]\[][]\[]3']['[-]?'''
#
#
# test3 = translate_new_alphabet('A new alphabet!')
# assert test3 == '''@ []\[]3\/\/ @1|D[-]@83']['!'''
