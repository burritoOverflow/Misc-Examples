# note the more 'pythonic' way of performing the same 
# operation as the previous example. These operations return
# a file object. Also, the 'with' keyword here sets up a try-catch-finally
# operation behind the scenes, so there is no need to close the files manually.

with open("foo", "rb") as fin:
    with open("bar", "wb") as fout:
        fout.write(fin.read())
