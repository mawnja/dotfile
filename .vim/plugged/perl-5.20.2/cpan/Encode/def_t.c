/*
 !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 This file was autogenerated by:
 /home/wenjian.ma/.vim/plugged/perl-5.20.2/miniperl bin/enc2xs -Q -O -o def_t.c -f def_t.fnm
 enc2xs VERSION 2.12
*/
#include "encode.h"

static const encpage_t utf8_iso_8859_1[4];

static const U8 enctable[512] = { 194,128,194,129,194,130,194,131,194,132,
194,133,194,134,194,135,194,136,194,137,194,138,194,139,194,140,194,141,194,
142,194,143,194,144,194,145,194,146,194,147,194,148,194,149,194,150,194,151,
194,152,194,153,194,154,194,155,194,156,194,157,194,158,194,159,194,160,194,
161,194,162,194,163,194,164,194,165,194,166,194,167,194,168,194,169,194,170,
194,171,194,172,194,173,194,174,194,175,194,176,194,177,194,178,194,179,194,
180,194,181,194,182,194,183,194,184,194,185,194,186,194,187,194,188,194,189,
194,190,194,191,195,128,195,129,195,130,195,131,195,132,195,133,195,134,195,
135,195,136,195,137,195,138,195,139,195,140,195,141,195,142,195,143,195,144,
195,145,195,146,195,147,195,148,195,149,195,150,195,151,195,152,195,153,195,
154,195,155,195,156,195,157,195,158,195,159,195,160,195,161,195,162,195,163,
195,164,195,165,195,166,195,167,195,168,195,169,195,170,195,171,195,172,195,
173,195,174,195,175,195,176,195,177,195,178,195,179,195,180,195,181,195,182,
195,183,195,184,195,185,195,186,195,187,195,188,195,189,195,190,195,191,0,1,2,
3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,
57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,
83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,
106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,
125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,
163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,
182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,
201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,
220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,
239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255 };

static const encpage_t ascii_utf8[2] = {
{enctable + 256,ascii_utf8,0x00,0x7f,1,1},
{0,ascii_utf8,0x80,0xff,0,0},
};

static const encpage_t utf8_ascii[2] = {
{enctable + 256,utf8_ascii,0x00,0x7f,1,1},
{0,utf8_ascii,0x80,0xff,0,0},
};

static const encpage_t ascii_ctrl_utf8[2] = {
{enctable + 256,ascii_ctrl_utf8,0x00,0x1f,1,1},
{0,ascii_ctrl_utf8,0x20,0xff,0,0},
};

static const encpage_t utf8_ascii_ctrl[2] = {
{enctable + 256,utf8_ascii_ctrl,0x00,0x1f,1,1},
{0,utf8_ascii_ctrl,0x20,0xff,0,0},
};

static const encpage_t iso_8859_1_utf8[2] = {
{enctable + 256,iso_8859_1_utf8,0x00,0x7f,1,1},
{enctable + 0,iso_8859_1_utf8,0x80,0xff,2,1},
};

static const encpage_t utf8_iso_8859_1_c2[2] = {
{enctable + 384,utf8_iso_8859_1,0x80,0xbf,1,1},
{0,utf8_iso_8859_1_c2,0xc0,0xff,0,0},
};

static const encpage_t utf8_iso_8859_1_c3[2] = {
{enctable + 448,utf8_iso_8859_1,0x80,0xbf,1,1},
{0,utf8_iso_8859_1_c3,0xc0,0xff,0,0},
};

static const encpage_t utf8_iso_8859_1[4] = {
{enctable + 256,utf8_iso_8859_1,0x00,0x7f,1,1},
{0,utf8_iso_8859_1_c2,0xc2,0xc2,0,2},
{0,utf8_iso_8859_1_c3,0xc3,0xc3,0,2},
{0,utf8_iso_8859_1,0xc4,0xff,0,0},
};

static const encpage_t null_utf8[1] = {
{0,null_utf8,0x01,0xff,0,0},
};

static const encpage_t utf8_null[1] = {
{0,utf8_null,0x01,0xff,0,0},
};
static const U8 ascii_encoding_rep_character[] = "\x3F";
static const char ascii_encoding_enc_name[] = "ascii";

 const encode_t ascii_encoding = 
 {ascii_utf8,utf8_ascii,ascii_encoding_rep_character,1,1,1,{ascii_encoding_enc_name,(const char *)0}};

static const U8 ascii_ctrl_encoding_rep_character[] = "\x3F";
static const char ascii_ctrl_encoding_enc_name[] = "ascii-ctrl";

 const encode_t ascii_ctrl_encoding = 
 {ascii_ctrl_utf8,utf8_ascii_ctrl,ascii_ctrl_encoding_rep_character,1,1,1,{ascii_ctrl_encoding_enc_name,(const char *)0}};

static const U8 iso_8859_1_encoding_rep_character[] = "\x3F";
static const char iso_8859_1_encoding_enc_name[] = "iso-8859-1";

 const encode_t iso_8859_1_encoding = 
 {iso_8859_1_utf8,utf8_iso_8859_1,iso_8859_1_encoding_rep_character,1,1,1,{iso_8859_1_encoding_enc_name,(const char *)0}};

static const U8 null_encoding_rep_character[] = "\x3F";
static const char null_encoding_enc_name[] = "null";

 const encode_t null_encoding = 
 {null_utf8,utf8_null,null_encoding_rep_character,1,1,1,{null_encoding_enc_name,(const char *)0}};

