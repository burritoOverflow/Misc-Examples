# note the more 'pythonic' way of performing the same 
# operation as the previous example

with open("foo", "rb") as fin:
    with open("bar", "wb") as fout:
        fout.write(fin.read())
