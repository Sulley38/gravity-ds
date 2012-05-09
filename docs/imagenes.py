from PIL import Image

im = Image.open("C:\\Users\\AAA\\Desktop\\3Dumb\\3Dumb.gif")
s=""
letras="ABCDEFGHIJKL"
for q in range(0,20,2):
    s += "u8 bitsNumeros"+letras[q/2]+"""[256] =
{
"""
    for outy in range(2):
        for outx in range(q,q+2):
            for iny in range(8):
                for inx in range(8):
                    s += str(im.getpixel((outx*8+inx,outy*8+iny)))+","
    s=s[0:len(s)-1]
    s +="\n};\n"
               

