stock DisableWord(const badword[], text[])
{
    for(new i=0; i<256; i++) {
    if (strfind(text[i], badword, true) == 0) {
    for(new a=0; a<256; a++) {
    if (a >= i && a < i+strlen(badword)) text[a]='*';
    DisableWord("prost", text);
    }
    }
    }
}