import os

bsize = 16384
fin = os.open("foo", os.O_RDONLY)
fout = os.open("bar", os.O_WRONLY | os.O_CREAT, 0o0644)

# note that the 'perform assign test' idiom doesn't work in python
# assignment statements are not expressions in python

# note also the buffer is repopulated on each interation
# unlike in the C version where the same buffer is used throughout
while 1:
    buf = os.read(fin, bsize)
    if buf:
        os.write(fout, buf)
    else:
        break

os.close(fin)
os.close(fout)
