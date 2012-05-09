from PIL import Image

im = Image.open("C:\\Users\\AAA\\Desktop\\3Dumb\\3Dumb.gif")
data=im.palette.getdata()[1]
s=""
for i in range(3,len(data),3):
    s +="VRAM_F_EXT_SPR_PALETTE[4]["+str(i/3)+"] = RGB15("+str(ord(data[i])/8)+", "+str(ord(data[i+1])/8)+", "+str(ord(data[i+2])/8)+ "); "

