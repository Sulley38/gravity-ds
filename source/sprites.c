/**
 * Definici�n de todos los sprites del juego
 * Las funciones cargan los sprites en la memoria al inicio
 */

#include <nds.h>
#include "defines.h"
#include "sprites.h"

/* Direcciones de memoria en las que est�n guardados los sprites */
u16* cuadrado;
u16* cuadrado2;
u16* corredor[4];
u16* bloque;


/* Inicializa la memoria de sprites */
void initSpriteMem() {

	oamInit(&oamMain, SpriteMapping_1D_32, FALSE);
	oamInit(&oamSub, SpriteMapping_1D_32, FALSE);

	/* Reserva de memoria para cada sprite que quiera incluirse en la pantalla */
	cuadrado = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	cuadrado2 = oamAllocateGfx(&oamMain, SpriteSize_64x64, SpriteColorFormat_256Color);
	bloque = oamAllocateGfx(&oamMain, SpriteSize_64x32, SpriteColorFormat_256Color);
	corredor[0] = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	corredor[1] = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	corredor[2] = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
	corredor[3] = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
}


/* Define los colores posibles para el estado 'Menu'.
 * El 0 es transparente y los no definidos son negros.
 * Esta paleta es usada para representar los botones del men�.
 */
void establecerPaletaMenu() {
	SPRITE_PALETTE[1] = RGB15(0, 0, 31); SPRITE_PALETTE[2] = RGB15(31, 0, 0);
}

/* Define los colores posibles para el estado 'Avanzar personaje'.
 * El 0 es transparente y los no definidos son negros.
 * Esta paleta es usada para representar el personaje, las plataformas y las monedas.
 */
void establecerPaletaAvanzarPersonaje() {
	SPRITE_PALETTE[1] = RGB15(0, 0, 16); SPRITE_PALETTE[2] = RGB15(0, 16, 0); SPRITE_PALETTE[3] = RGB15(0, 16, 16); SPRITE_PALETTE[4] = RGB15(16, 0, 0); SPRITE_PALETTE[5] = RGB15(16, 0, 16); SPRITE_PALETTE[6] = RGB15(16, 16, 0); SPRITE_PALETTE[7] = RGB15(24, 24, 24); SPRITE_PALETTE[8] = RGB15(24, 27, 24); SPRITE_PALETTE[9] = RGB15(30, 25, 20); SPRITE_PALETTE[10] = RGB15(0, 4, 8); SPRITE_PALETTE[11] = RGB15(0, 4, 12); SPRITE_PALETTE[12] = RGB15(0, 4, 16); SPRITE_PALETTE[13] = RGB15(0, 4, 20); SPRITE_PALETTE[14] = RGB15(0, 4, 24); SPRITE_PALETTE[15] = RGB15(0, 4, 28); SPRITE_PALETTE[16] = RGB15(0, 8, 0); SPRITE_PALETTE[17] = RGB15(0, 8, 4); SPRITE_PALETTE[18] = RGB15(0, 8, 8); SPRITE_PALETTE[19] = RGB15(0, 8, 12); SPRITE_PALETTE[20] = RGB15(0, 8, 16); SPRITE_PALETTE[21] = RGB15(0, 8, 20); SPRITE_PALETTE[22] = RGB15(0, 8, 24); SPRITE_PALETTE[23] = RGB15(0, 8, 28); SPRITE_PALETTE[24] = RGB15(0, 12, 0); SPRITE_PALETTE[25] = RGB15(0, 12, 4); SPRITE_PALETTE[26] = RGB15(0, 12, 8); SPRITE_PALETTE[27] = RGB15(0, 12, 12); SPRITE_PALETTE[28] = RGB15(0, 12, 16); SPRITE_PALETTE[29] = RGB15(0, 12, 20); SPRITE_PALETTE[30] = RGB15(0, 12, 24); SPRITE_PALETTE[31] = RGB15(0, 12, 28); SPRITE_PALETTE[32] = RGB15(0, 16, 0);
	SPRITE_PALETTE[33] = RGB15(0, 16, 4); SPRITE_PALETTE[34] = RGB15(0, 16, 8); SPRITE_PALETTE[35] = RGB15(0, 16, 12); SPRITE_PALETTE[36] = RGB15(0, 16, 16); SPRITE_PALETTE[37] = RGB15(0, 16, 20); SPRITE_PALETTE[38] = RGB15(0, 16, 24); SPRITE_PALETTE[39] = RGB15(0, 16, 28); SPRITE_PALETTE[40] = RGB15(0, 20, 0); SPRITE_PALETTE[41] = RGB15(0, 20, 4); SPRITE_PALETTE[42] = RGB15(0, 20, 8); SPRITE_PALETTE[43] = RGB15(0, 20, 12); SPRITE_PALETTE[44] = RGB15(0, 20, 16); SPRITE_PALETTE[45] = RGB15(0, 20, 20); SPRITE_PALETTE[46] = RGB15(0, 20, 24); SPRITE_PALETTE[47] = RGB15(0, 20, 28); SPRITE_PALETTE[48] = RGB15(0, 24, 0); SPRITE_PALETTE[49] = RGB15(0, 24, 4); SPRITE_PALETTE[50] = RGB15(0, 24, 8); SPRITE_PALETTE[51] = RGB15(0, 24, 12); SPRITE_PALETTE[52] = RGB15(0, 24, 16); SPRITE_PALETTE[53] = RGB15(0, 24, 20); SPRITE_PALETTE[54] = RGB15(0, 24, 24); SPRITE_PALETTE[55] = RGB15(0, 24, 28); SPRITE_PALETTE[56] = RGB15(0, 28, 0); SPRITE_PALETTE[57] = RGB15(0, 28, 4); SPRITE_PALETTE[58] = RGB15(0, 28, 8); SPRITE_PALETTE[59] = RGB15(0, 28, 12); SPRITE_PALETTE[60] = RGB15(0, 28, 16); SPRITE_PALETTE[61] = RGB15(0, 28, 20); SPRITE_PALETTE[62] = RGB15(0, 28, 24); SPRITE_PALETTE[63] = RGB15(0, 28, 28); SPRITE_PALETTE[64] = RGB15(8, 0, 0);
	SPRITE_PALETTE[65] = RGB15(8, 0, 4); SPRITE_PALETTE[66] = RGB15(8, 0, 8); SPRITE_PALETTE[67] = RGB15(8, 0, 12); SPRITE_PALETTE[68] = RGB15(8, 0, 16); SPRITE_PALETTE[69] = RGB15(8, 0, 20); SPRITE_PALETTE[70] = RGB15(8, 0, 24); SPRITE_PALETTE[71] = RGB15(8, 0, 28); SPRITE_PALETTE[72] = RGB15(8, 4, 0); SPRITE_PALETTE[73] = RGB15(8, 4, 4); SPRITE_PALETTE[74] = RGB15(8, 4, 8); SPRITE_PALETTE[75] = RGB15(8, 4, 12); SPRITE_PALETTE[76] = RGB15(8, 4, 16); SPRITE_PALETTE[77] = RGB15(8, 4, 20); SPRITE_PALETTE[78] = RGB15(8, 4, 24); SPRITE_PALETTE[79] = RGB15(8, 4, 28); SPRITE_PALETTE[80] = RGB15(8, 8, 0); SPRITE_PALETTE[81] = RGB15(8, 8, 4); SPRITE_PALETTE[82] = RGB15(8, 8, 8); SPRITE_PALETTE[83] = RGB15(8, 8, 12); SPRITE_PALETTE[84] = RGB15(8, 8, 16); SPRITE_PALETTE[85] = RGB15(8, 8, 20); SPRITE_PALETTE[86] = RGB15(8, 8, 24); SPRITE_PALETTE[87] = RGB15(8, 8, 28); SPRITE_PALETTE[88] = RGB15(8, 12, 0); SPRITE_PALETTE[89] = RGB15(8, 12, 4); SPRITE_PALETTE[90] = RGB15(8, 12, 8); SPRITE_PALETTE[91] = RGB15(8, 12, 12); SPRITE_PALETTE[92] = RGB15(8, 12, 16); SPRITE_PALETTE[93] = RGB15(8, 12, 20); SPRITE_PALETTE[94] = RGB15(8, 12, 24); SPRITE_PALETTE[95] = RGB15(8, 12, 28); SPRITE_PALETTE[96] = RGB15(8, 16, 0);
	SPRITE_PALETTE[97] = RGB15(8, 16, 4); SPRITE_PALETTE[98] = RGB15(8, 16, 8); SPRITE_PALETTE[99] = RGB15(8, 16, 12); SPRITE_PALETTE[100] = RGB15(8, 16, 16); SPRITE_PALETTE[101] = RGB15(8, 16, 20); SPRITE_PALETTE[102] = RGB15(8, 16, 24); SPRITE_PALETTE[103] = RGB15(8, 16, 28); SPRITE_PALETTE[104] = RGB15(8, 20, 0); SPRITE_PALETTE[105] = RGB15(8, 20, 4); SPRITE_PALETTE[106] = RGB15(8, 20, 8); SPRITE_PALETTE[107] = RGB15(8, 20, 12); SPRITE_PALETTE[108] = RGB15(8, 20, 16); SPRITE_PALETTE[109] = RGB15(8, 20, 20); SPRITE_PALETTE[110] = RGB15(8, 20, 24); SPRITE_PALETTE[111] = RGB15(8, 20, 28); SPRITE_PALETTE[112] = RGB15(8, 24, 0); SPRITE_PALETTE[113] = RGB15(8, 24, 4); SPRITE_PALETTE[114] = RGB15(8, 24, 8); SPRITE_PALETTE[115] = RGB15(8, 24, 12); SPRITE_PALETTE[116] = RGB15(8, 24, 16); SPRITE_PALETTE[117] = RGB15(8, 24, 20); SPRITE_PALETTE[118] = RGB15(8, 24, 24); SPRITE_PALETTE[119] = RGB15(8, 24, 28); SPRITE_PALETTE[120] = RGB15(8, 28, 0); SPRITE_PALETTE[121] = RGB15(8, 28, 4); SPRITE_PALETTE[122] = RGB15(8, 28, 8); SPRITE_PALETTE[123] = RGB15(8, 28, 12); SPRITE_PALETTE[124] = RGB15(8, 28, 16); SPRITE_PALETTE[125] = RGB15(8, 28, 20); SPRITE_PALETTE[126] = RGB15(8, 28, 24); SPRITE_PALETTE[127] = RGB15(8, 28, 28); SPRITE_PALETTE[128] = RGB15(16, 0, 0);
	SPRITE_PALETTE[129] = RGB15(16, 0, 4); SPRITE_PALETTE[130] = RGB15(16, 0, 8); SPRITE_PALETTE[131] = RGB15(16, 0, 12); SPRITE_PALETTE[132] = RGB15(16, 0, 16); SPRITE_PALETTE[133] = RGB15(16, 0, 20); SPRITE_PALETTE[134] = RGB15(16, 0, 24); SPRITE_PALETTE[135] = RGB15(16, 0, 28); SPRITE_PALETTE[136] = RGB15(16, 4, 0); SPRITE_PALETTE[137] = RGB15(16, 4, 4); SPRITE_PALETTE[138] = RGB15(16, 4, 8); SPRITE_PALETTE[139] = RGB15(16, 4, 12); SPRITE_PALETTE[140] = RGB15(16, 4, 16); SPRITE_PALETTE[141] = RGB15(16, 4, 20); SPRITE_PALETTE[142] = RGB15(16, 4, 24); SPRITE_PALETTE[143] = RGB15(16, 4, 28); SPRITE_PALETTE[144] = RGB15(16, 8, 0); SPRITE_PALETTE[145] = RGB15(16, 8, 4); SPRITE_PALETTE[146] = RGB15(16, 8, 8); SPRITE_PALETTE[147] = RGB15(16, 8, 12); SPRITE_PALETTE[148] = RGB15(16, 8, 16); SPRITE_PALETTE[149] = RGB15(16, 8, 20); SPRITE_PALETTE[150] = RGB15(16, 8, 24); SPRITE_PALETTE[151] = RGB15(16, 8, 28); SPRITE_PALETTE[152] = RGB15(16, 12, 0); SPRITE_PALETTE[153] = RGB15(16, 12, 4); SPRITE_PALETTE[154] = RGB15(16, 12, 8); SPRITE_PALETTE[155] = RGB15(16, 12, 12); SPRITE_PALETTE[156] = RGB15(16, 12, 16); SPRITE_PALETTE[157] = RGB15(16, 12, 20); SPRITE_PALETTE[158] = RGB15(16, 12, 24); SPRITE_PALETTE[159] = RGB15(16, 12, 28); SPRITE_PALETTE[160] = RGB15(16, 16, 0);
	SPRITE_PALETTE[161] = RGB15(16, 16, 4); SPRITE_PALETTE[162] = RGB15(16, 16, 8); SPRITE_PALETTE[163] = RGB15(16, 16, 12); SPRITE_PALETTE[164] = RGB15(16, 16, 16); SPRITE_PALETTE[165] = RGB15(16, 16, 20); SPRITE_PALETTE[166] = RGB15(16, 16, 24); SPRITE_PALETTE[167] = RGB15(16, 16, 28); SPRITE_PALETTE[168] = RGB15(16, 20, 0); SPRITE_PALETTE[169] = RGB15(16, 20, 4); SPRITE_PALETTE[170] = RGB15(16, 20, 8); SPRITE_PALETTE[171] = RGB15(16, 20, 12); SPRITE_PALETTE[172] = RGB15(16, 20, 16); SPRITE_PALETTE[173] = RGB15(16, 20, 20); SPRITE_PALETTE[174] = RGB15(16, 20, 24); SPRITE_PALETTE[175] = RGB15(16, 20, 28); SPRITE_PALETTE[176] = RGB15(16, 24, 0); SPRITE_PALETTE[177] = RGB15(16, 24, 4); SPRITE_PALETTE[178] = RGB15(16, 24, 8); SPRITE_PALETTE[179] = RGB15(16, 24, 12); SPRITE_PALETTE[180] = RGB15(16, 24, 16); SPRITE_PALETTE[181] = RGB15(16, 24, 20); SPRITE_PALETTE[182] = RGB15(16, 24, 24); SPRITE_PALETTE[183] = RGB15(16, 24, 28); SPRITE_PALETTE[184] = RGB15(16, 28, 0); SPRITE_PALETTE[185] = RGB15(16, 28, 4); SPRITE_PALETTE[186] = RGB15(16, 28, 8); SPRITE_PALETTE[187] = RGB15(16, 28, 12); SPRITE_PALETTE[188] = RGB15(16, 28, 16); SPRITE_PALETTE[189] = RGB15(16, 28, 20); SPRITE_PALETTE[190] = RGB15(16, 28, 24); SPRITE_PALETTE[191] = RGB15(16, 28, 28); SPRITE_PALETTE[192] = RGB15(24, 0, 0);
	SPRITE_PALETTE[193] = RGB15(24, 0, 4); SPRITE_PALETTE[194] = RGB15(24, 0, 8); SPRITE_PALETTE[195] = RGB15(24, 0, 12); SPRITE_PALETTE[196] = RGB15(24, 0, 16); SPRITE_PALETTE[197] = RGB15(24, 0, 20); SPRITE_PALETTE[198] = RGB15(24, 0, 24); SPRITE_PALETTE[199] = RGB15(24, 0, 28); SPRITE_PALETTE[200] = RGB15(24, 4, 0); SPRITE_PALETTE[201] = RGB15(24, 4, 4); SPRITE_PALETTE[202] = RGB15(24, 4, 8); SPRITE_PALETTE[203] = RGB15(24, 4, 12); SPRITE_PALETTE[204] = RGB15(24, 4, 16); SPRITE_PALETTE[205] = RGB15(24, 4, 20); SPRITE_PALETTE[206] = RGB15(24, 4, 24); SPRITE_PALETTE[207] = RGB15(24, 4, 28); SPRITE_PALETTE[208] = RGB15(24, 8, 0); SPRITE_PALETTE[209] = RGB15(24, 8, 4); SPRITE_PALETTE[210] = RGB15(24, 8, 8); SPRITE_PALETTE[211] = RGB15(24, 8, 12); SPRITE_PALETTE[212] = RGB15(24, 8, 16); SPRITE_PALETTE[213] = RGB15(24, 8, 20); SPRITE_PALETTE[214] = RGB15(24, 8, 24); SPRITE_PALETTE[215] = RGB15(24, 8, 28); SPRITE_PALETTE[216] = RGB15(24, 12, 0); SPRITE_PALETTE[217] = RGB15(24, 12, 4); SPRITE_PALETTE[218] = RGB15(24, 12, 8); SPRITE_PALETTE[219] = RGB15(24, 12, 12); SPRITE_PALETTE[220] = RGB15(24, 12, 16); SPRITE_PALETTE[221] = RGB15(24, 12, 20); SPRITE_PALETTE[222] = RGB15(24, 12, 24); SPRITE_PALETTE[223] = RGB15(24, 12, 28); SPRITE_PALETTE[224] = RGB15(24, 16, 0);
	SPRITE_PALETTE[225] = RGB15(24, 16, 4); SPRITE_PALETTE[226] = RGB15(24, 16, 8); SPRITE_PALETTE[227] = RGB15(24, 16, 12); SPRITE_PALETTE[228] = RGB15(24, 16, 16); SPRITE_PALETTE[229] = RGB15(24, 16, 20); SPRITE_PALETTE[230] = RGB15(24, 16, 24); SPRITE_PALETTE[231] = RGB15(24, 16, 28); SPRITE_PALETTE[232] = RGB15(24, 20, 0); SPRITE_PALETTE[233] = RGB15(24, 20, 4); SPRITE_PALETTE[234] = RGB15(24, 20, 8); SPRITE_PALETTE[235] = RGB15(24, 20, 12); SPRITE_PALETTE[236] = RGB15(24, 20, 16); SPRITE_PALETTE[237] = RGB15(24, 20, 20); SPRITE_PALETTE[238] = RGB15(24, 20, 24); SPRITE_PALETTE[239] = RGB15(24, 20, 28); SPRITE_PALETTE[240] = RGB15(24, 24, 0); SPRITE_PALETTE[241] = RGB15(24, 24, 4); SPRITE_PALETTE[242] = RGB15(24, 24, 8); SPRITE_PALETTE[243] = RGB15(24, 24, 12); SPRITE_PALETTE[244] = RGB15(24, 24, 16); SPRITE_PALETTE[245] = RGB15(24, 24, 20); SPRITE_PALETTE[246] = RGB15(30, 31, 31); SPRITE_PALETTE[247] = RGB15(20, 20, 20); SPRITE_PALETTE[248] = RGB15(16, 16, 16); SPRITE_PALETTE[249] = RGB15(0, 0, 31); SPRITE_PALETTE[250] = RGB15(0, 31, 0); SPRITE_PALETTE[251] = RGB15(0, 31, 31); SPRITE_PALETTE[252] = RGB15(31, 0, 0); SPRITE_PALETTE[253] = RGB15(31, 0, 31); SPRITE_PALETTE[254] = RGB15(31, 31, 0); SPRITE_PALETTE[255] = RGB15(31, 31, 31);
	//Para la pantalla secundaria: SPRITE_PALETTE_SUB[]
}


/* Estructuras de los sprites */
u8 bitsCorredorA[1024] =
{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,234,0,0,0,0,0,0,0,234,242,0,0,0,0,0,217,233,254,254,0,0,0,0,0,153,233,242,9,0,0,153,154,154,0,0,244,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,171,171,0,0,0,0,0,172,236,247,245,245,0,171,236,163,0,0,155,155,171,8,8,0,154,154,163,172,8,255,245,0,90,154,82,82,0,0,154,163,236,236,244,9,0,0,0,163,8,255,255,246,0,0,0,155,247,8,8,8,154,154,82,155,91,164,247,7,163,155,74,154,155,91,164,164,7,246,255,154,154,90,91,91,82,91,7,154,154,0,0,0,255,255,7,155,155,81,73,0,163,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,7,164,0,0,0,0,0,0,247,164,0,0,0,0,0,0,164,163,0,0,0,0,0,0,91,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,0,0,0,0,0,0,154,91,164,0,0,0,0,154,90,155,247,0,0,0,0,82,155,164,247,0,0,0,82,91,90,155,163,0,0,82,82,164,154,154,0,7,255,7,154,172,154,90,247,163,245,247,82,82,73,82,255,0,0,0,81,82,82,91,83,163,0,0,0,90,0,91,7,245,0,0,0,0,0,91,91,245,171,0,0,0,0,91,91,0,163,164,0,0,91,0,0,0,0,0,163,247,0,0,0,255,255,246,82,91,90,82,0,154,7,155,91,91,90,154,154,90,154,154,0,0,82,82,163,7,164,237,164,163,0,0,163,7,7,247,164,163,0,0,163,0,0,163,163,0,163,163,0,0,0,0,0,163,163,163,0,0,0,0,0,0,163,163,163,0,0,0,0,0,0,0,0,0,0,0,0,0,236,236,0,0,0,0,0,236,7,247,0,163,0,236,245,163,163,163,0,163,236,247,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,163,236,171,163,0,0,0,82,82,91,90,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,163,163,0,0,0,0,0,0,163,236,0,0,0,0,0,0,171,7,0,0,0,0,0,0,163,247,0,0,0,0,0,0,163,172,0,0,0,0,0,0,0,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,245,236,236,235,163,0,237,245,245,7,7,172,163,0,246,7,246,247,7,155,0,0,164,164,91,155,163,0,0,0,91,91,154,163,0,0,0,0,154,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

u8 bitsCorredorB[1024] =
{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,242,0,0,0,0,0,153,233,254,241,0,0,0,0,154,233,254,254,234,0,225,241,233,161,233,243,243,0,0,154,244,235,0,235,235,0,0,163,255,255,255,245,247,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,164,163,0,0,0,0,0,0,82,154,0,0,0,0,0,0,0,0,0,0,0,0,154,255,255,154,0,0,0,154,255,90,154,154,0,154,154,255,82,154,90,81,0,154,255,154,154,154,73,82,154,255,82,154,154,82,7,246,172,154,90,91,82,246,246,7,82,81,90,154,255,255,8,247,0,163,255,255,255,7,247,0,163,163,247,8,8,247,247,0,91,82,164,247,247,247,164,0,154,154,91,155,155,155,91,0,164,246,90,91,91,91,0,0,255,164,154,0,0,0,0,0,246,247,154,0,0,0,0,0,245,247,90,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,0,0,0,0,0,0,154,163,247,247,0,0,0,0,163,163,164,7,82,154,82,82,255,155,7,247,0,0,91,155,82,154,82,82,0,0,155,246,255,91,154,90,0,0,0,247,246,164,0,0,0,0,0,172,8,164,0,0,0,0,0,163,247,164,0,0,0,0,0,0,163,163,0,0,255,255,246,255,246,163,0,0,247,247,154,0,0,0,0,0,237,246,171,163,0,0,0,0,82,154,163,247,7,8,7,236,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,171,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,154,154,155,163,0,0,0,0,155,155,154,154,0,0,0,154,154,154,154,0,0,0,154,154,154,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,164,172,163,0,0,0,0,0,0,0,0,0,0,163,163,0,0,0,0,0,0,163,163,0,0,0,0,0,0,245,245,0,0,0,0,0,0,245,246,0,0,0,0,0,0,235,243,0,0,0,0,0,234,242,242,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,164,90,163,163,163,0,0,255,255,255,172,154,0,0,0,172,163,163,163,171,163,0,0,254,254,254,254,254,242,234,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

u8 bitsCorredorC[1024] =
{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,226,0,241,0,0,0,0,0,0,80,241,0,0,0,0,0,0,0,225,0,0,0,0,153,234,0,0,0,0,0,0,0,154,245,9,0,0,0,0,154,163,245,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,254,254,0,0,0,0,0,0,254,9,0,0,0,0,0,0,234,243,163,0,0,0,0,0,9,9,245,0,0,0,0,0,255,246,7,164,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,237,0,0,0,0,0,154,255,154,0,0,0,0,0,247,82,154,0,0,0,0,0,155,154,154,0,0,0,154,90,90,82,90,0,0,0,155,90,154,0,90,0,154,246,164,163,155,247,246,255,255,154,154,154,154,154,247,154,154,154,154,82,82,82,91,154,154,154,154,90,90,90,154,154,154,90,90,91,91,91,82,90,82,82,82,247,246,255,7,154,8,255,8,247,91,91,246,90,245,154,164,155,91,154,155,246,8,245,172,0,0,0,0,7,7,247,164,0,0,0,0,164,164,164,155,0,0,0,0,91,91,0,0,0,0,0,0,154,0,0,0,0,0,0,0,154,0,0,0,0,0,0,236,236,0,0,0,0,163,8,255,7,236,0,0,236,7,245,172,0,0,0,0,0,0,0,163,0,0,0,0,0,0,154,155,0,0,0,0,0,154,164,91,0,0,0,0,155,247,164,82,0,0,0,154,91,237,164,90,0,0,154,82,91,163,163,155,0,0,0,90,155,155,154,0,0,0,0,0,0,0,0,0,154,0,0,154,90,0,0,91,247,171,0,155,155,0,0,164,164,246,7,0,0,0,0,247,164,172,8,171,0,0,236,246,163,163,172,246,163,0,237,7,0,0,0,163,7,171,171,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,91,82,90,154,82,0,0,0,255,255,91,82,90,154,0,0,255,247,155,0,0,154,0,0,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,154,0,0,0,0,0,0,0,164,0,0,0,0,0,0,0,247,236,236,171,236,247,163,163,163,0,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,0,0,0,0,0,245,163,236,163,0,0,0,163,247,245,245,163,154,0,155,90,172,247,247,154,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,247,0,0,0,0,0,0,0,155,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,164,82,164,155,155,154,154,0,155,82,90,90,154,154,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
u8 bitsCorredorD[1024] =
{
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,242,0,0,0,0,0,153,233,254,241,0,0,0,0,154,233,254,254,234,0,225,241,233,161,233,243,243,0,0,154,244,235,0,235,235,0,0,163,255,255,255,245,247,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,164,163,0,0,0,0,0,0,82,154,0,0,0,0,0,0,0,0,0,0,0,0,154,255,255,154,0,0,0,154,255,90,154,154,0,154,154,255,82,154,90,81,0,154,255,154,154,154,73,82,154,255,82,154,154,82,7,246,172,154,90,91,82,246,246,7,82,81,90,154,255,255,8,247,0,163,255,255,255,7,247,0,163,163,247,8,8,247,247,0,91,82,164,247,247,247,164,0,154,154,91,155,155,155,91,0,164,246,90,91,91,91,0,0,255,164,154,0,0,0,0,0,246,247,154,0,0,0,0,0,245,247,90,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,0,0,0,0,0,0,154,163,247,247,0,0,0,0,163,163,164,7,82,154,82,82,255,155,7,247,0,0,91,155,82,154,82,82,0,0,155,246,255,91,154,90,0,0,0,247,246,164,0,0,0,0,0,172,8,164,0,0,0,0,0,163,247,164,0,0,0,0,0,0,163,163,0,0,255,255,246,255,246,163,0,0,247,247,154,0,0,0,0,0,237,246,171,163,0,0,0,0,82,154,163,247,7,8,7,236,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,171,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,154,154,155,163,0,0,0,0,155,155,154,154,0,0,0,154,154,154,154,0,0,0,154,154,154,154,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,163,164,172,163,0,0,0,0,0,0,0,0,0,0,163,163,0,0,0,0,0,0,163,163,0,0,0,0,0,0,245,245,0,0,0,0,0,0,245,246,0,0,0,0,0,0,235,243,0,0,0,0,0,234,242,242,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,164,90,163,163,163,0,0,255,255,255,172,154,0,0,0,172,163,163,163,171,163,0,0,254,254,254,254,254,242,234,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

u8 bitsBloque[2048] =
{
		246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,91,91,91,91,91,91,91,91,73,73,73,73,73,73,73,73,82,247,164,247,164,73,73,73,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,91,155,91,91,91,91,155,91,73,73,73,73,73,73,73,73,73,82,247,164,164,164,73,73,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,91,155,91,91,91,91,91,155,73,73,73,73,73,73,73,73,73,73,73,164,164,164,164,82,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,155,155,155,155,91,91,91,91,73,73,73,73,73,73,73,73,0,73,0,82,247,164,164,164,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,155,155,91,91,91,91,91,91,73,73,73,73,73,73,73,73,73,73,73,0,82,247,164,247,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,91,91,91,91,91,155,91,91,73,73,73,73,73,73,73,73,164,73,73,73,73,82,247,164,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,91,91,155,91,91,155,91,91,73,73,73,73,73,73,73,73,164,164,73,73,73,73,73,164,246,246,246,246,246,246,246,246,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,91,91,91,155,155,155,155,155,73,73,73,73,73,73,73,73,164,164,164,82,0,73,0,82,155,7,7,7,245,73,0,73,91,7,237,7,247,73,0,0,82,7,7,7,172,73,73,73,82,247,247,247,163,73,82,82,0,155,155,164,82,73,82,82,73,0,0,0,0,82,82,82,82,0,0,0,73,82,82,82,82,73,73,82,82,73,73,73,73,82,7,7,7,7,82,0,73,82,237,245,245,247,82,0,73,82,237,7,7,247,73,0,82,73,172,247,247,164,73,82,82,73,155,164,164,82,0,82,82,73,0,0,0,0,82,82,82,82,0,0,0,73,82,82,73,73,82,82,82,73,73,73,73,0,82,7,7,7,7,82,73,0,82,247,245,237,237,82,73,0,74,237,7,7,237,73,82,82,73,164,247,247,164,73,82,82,0,91,164,164,91,73,82,82,73,0,0,0,0,73,82,82,82,0,0,0,73,82,73,73,73,82,73,73,73,73,0,73,0,91,7,7,7,7,0,73,0,91,237,237,7,247,0,73,0,82,7,7,7,247,82,82,82,73,247,247,247,164,82,82,82,0,155,164,164,82,82,82,82,73,0,0,0,0,82,82,82,82,0,0,0,73,73,73,73,73,73,73,73,73,82,0,73,0,155,7,7,7,73,0,73,0,91,7,237,7,73,0,73,0,82,7,7,7,73,82,82,82,82,247,247,247,73,82,82,82,0,155,155,164,82,82,82,82,73,0,0,0,82,82,82,82,82,0,0,0,73,73,73,73,82,73,73,82,245,73,0,73,73,82,7,7,247,73,0,0,73,82,237,245,172,73,73,73,73,82,237,7,163,73,82,82,82,73,172,247,82,73,82,82,82,73,155,164,0,82,82,82,82,73,0,0,73,82,82,82,82,82,0,0,82,73,73,73,73,73,82,82,7,7,82,0,73,0,82,7,245,247,82,0,73,0,82,247,7,247,73,0,73,0,74,237,247,164,73,82,82,82,73,164,164,82,0,82,82,82,0,91,0,0,82,82,82,82,73,0,0,73,82,82,82,82,82,0,82,73,73,73,73,73,73,82,7,7,7,82,0,73,0,91,245,237,237,82,0,73,0,91,7,7,237,73,0,73,0,82,247,247,164,73,82,82,82,73,164,164,91,73,82,82,82,0,0,0,0,73,82,82,82,73,0,0,73,82,82,82,82,82,73,73,73,73,73,73,73,73,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,
		9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,164,164,164,164,164,164,164,164,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,247,246,246,246,246,246,246,246,246,163,163,163,163,163,163,163,163,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,163,163,163,163,163,163,163,163,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,8,7,7,7,7,7,7,8,8,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,246,246,246,246,246,246,246,246,155,155,155,155,155,155,155,155,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7
};


/* Guarda los sprites en memoria para luego poder usarlos */
void guardarSpritesEnMemoria(){
	int i;
	for(i = 0; i < 64 * 64 / 2; i++) {
		cuadrado[i] = 1 | (1 << 8);
		cuadrado2[i] = 2 | (2 << 8);
	}
	for(i = 0; i < 32 * 32 / 2; i++){
		corredor[0][i] = bitsCorredorA[i*2] | (bitsCorredorA[(i*2)+1]<<8);
		corredor[1][i] = bitsCorredorB[i*2] | (bitsCorredorB[(i*2)+1]<<8);
		corredor[2][i] = bitsCorredorC[i*2] | (bitsCorredorC[(i*2)+1]<<8);
		corredor[3][i] = bitsCorredorD[i*2] | (bitsCorredorD[(i*2)+1]<<8);
	}
	for(i = 0; i < 64 * 16 / 2; i++){
		bloque[i] = bitsBloque[i*2] | (bitsBloque[(i*2)+1]<<8);
	}
}
