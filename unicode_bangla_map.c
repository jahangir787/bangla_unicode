#include<stdio.h>
int main(){
	int a[10];
	int i, ch;
	i = 0;
	while(scanf("%c", &ch) == 1){
		if('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || 0x09e6 <= ch && ch <= 0x09ef){
			switch(ch){
				case 'k':
					a[i] = 0x0995; // ক
					i ++ ;
					break;
				case 'h':
					if(a[i-1] == 0x0995) // previous character is ক
					{
					  a[i-1] = 0x0996; // খ
					  i = i - 1;
					}else if(a[i-1] == 0x0997){ // previous char গ
						a[i-1] = 0x0998; 
						i = i - 1;
					}
					else if(a[i-1] == 0x099a){ // previous char চ
						a[i-1] = 0x099b; // ছ
						i = i - 1;
					}
					else if(a[i-1] == 0x099c){ // previous char জ
						a[i-1] = 0x099d; // ঝ
						i = i - 1;
					}
					else if(a[i-1] == 0x099f){ // previous char ট
						a[i-1] = 0x09a0; // ঠ
						i = i - 1;
					}
					else if(a[i-1] == 0x09a1) // previous char ড
					{
						a[i-1] = 0x09a2; // ঢ
						i = i - 1;
					}
					else if (a[i-1] == 0x09a4){ // ত
						a[i-1] = 0x09a5; // থ
						i = i - 1;
					}
					else if(a[i-1] == 0x09a6){ // previous দ)
						a[i-1] = 0x09a7; // ধ
						i = i - 1;
					}
					else if(a[i-1] == 0x09b6){ // previous শ
						a[i-1] = 0x09b7; // ষ
						i -- ;
					}
					else if(a[i-1] == 0x09dc){ // previous ড়
						a[i-1] = 0x09dd; // ঢ়
						i -- ;
					} 
					else{
						a[i] = 0x09b9; // হ
					}
					break;
				// end case h
				case 'g':
					if(a[i-1] == 0x09a3){ // previous char ণ
						a[i-1] = 0x0999;
						i = i - 1;
					} else if(a[i-1] == 0x09a8){ // previous ন
						a[i-1] = 0x0982; // ং
						i -- ;
					}else{
						a[i] = 0x0997; // গ
					}
					break;
				case 'N':
					a[i] = 0x09a3; // ণ
					break;
				case 'G':
					if(a[i-1] == 0x09a3) // previous char ণ
					{
						a[i-1] = 0x099e; // ঞ
					}
					break;
				case 'c':
					a[i] = 0x099a; // চ
					break;
				case 'j':
					a[i] = 0x099c; // জ
					break;
				case 'T':
					a[i] = 0x099f; // ট
					break;
				case 'D':
					a[i] = 0x09a1; // ড
					break;
				case 't':
					a[i] = 0x09a4; // ত
					break;
				case 'd':
					a[i] = 0x09a6; // দ
					break;
				case '`':
					if (a[i-1] == 0x09a4){ // previous ত
						a[i-1] = 0x09ce; // ৎ
						i -- ;
					}else if(a[i-1] == 0x0983){
						a[i-1] = ':';
						i--;
					}
					break;
				case 'n':
					a[i] = 0x09a8; // ন
					break;
				case 'p':
					a[i] = 0x09aa;  // প
					break;
				case 'f':
					a[i] = 0x09ab; // ফ
					break;
				case 'b':
					a[i] = 0x09ac; // ব
					break;
				case 'v':
					a[i] = 0x09ad; // ভ
					break;
				case 'm':
					a[i] = 0x09ae; // ম
					break;
				case 'z':
					a[i] == 0x09af; // য
					break;
				case 'r':
					a[i] = 0x09b0; // র
					break;
				case 'l':
					a[i] = 0x09b2; // ল
					break;
				case 'S':
					a[i] = 0x09b6; // শ
					break;
				case 's':
					a[i] = 0x09b8; // স
					break;
				case 'R':
					a[i] = 0x09DC; // ড়
					break;
				case 'i':
					if(a[i-1] == 0x09b0 && a[i-2] == 0x09b0){ // previous র
						a[i-2] = 0x098b; // ঋ
					}else if(a[i-1] == 0x09b0 && a[i-2] == 0x09b0 && a[i-3] == 0x09b0){ // consecutive three r or র
						a[i-2] = 0x09c3; // rri kar
						i = i-2;
					}else if(i==0){// beginning of word
						a[i] = 0x0987; // ই
					}else if(i > 0){// not beginning of word
						a[i] = 0x09bf; // হ্রস্ব ই কার
					}
					break;
				case 'o':
					a[i] = 0x0985; // অ
					break;
				case 'I':
					if(i > 0){
						a[i] = 0x09c0; // ঈ কার
					}else if(i == 0){
						a[i] = 0x0988; // ঈ
					}
					break;
				case 'u':
					if(i == 0){
						a[i] = 0x0989; // উ
					}else if(a[0] == 0x0993 && i == 1){
						a[0] = 0x0994; // ঔ
					}else if(i > 0 && a[i-1] == 0x0993){
						a[i-1] = 0x09cc; // ঔ কার
						i --;
					}else if(i>0 && a[i-1] != 0x0993){
						a[i] = 0x09c1; // u kar
					}
					break;
				case 'U':
					if(i > 0){
						a[i] = 0x09c2; // ঊ কার
					}else if(i == 0){
						a[i] = 0x098a; // ঊ
					}
					break;
				case 'e':
					if(i > 0){
						a[i] = 0x09c7; // এ কার
					}else if(i==0){
						a[i] = 0x098f; // এ
					}
					break;
				case 'O':
					if(i==0){
						a[i] = 0x0993; // ও
					}else if(i > 0){
						a[i] = 0x09cb; // ও কার
					}
					break;
				case ':':
					a[i] = 0x0983;
					break;
				case 'y':
					a[i] = 0x09df;
					break;
				case '^':
					a[i] = 0x0981;
					break;
				case '.':
					a[i] = 0x09f7;
					break;
				case 'a':
					if(i == 0){
						a[i] = 0x0986;
					}else if(i > 0){
						a[i] = 0x09be;
					}
					break;
				case '0':
					a[i] = 0x09e6;
					break;
				case '1':
					a[i] = 0x09e7;
					break;
				case '2':
					a[i] = 0x09e8;
					break;
				case '3':
					a[i] = 0x09e9;
					break;
				case '4':
					a[i] = 0x09ea;
					break;
				case '5':
					a[i] = 0x09eb;
					break;
				case '6':
					a[i] = 0x09ec;
					break;
				case '7':
					a[i] = 0x09ed;
					break;
				case '8':
					a[i] = 0x09ee;
					break;
				case '9':
					a[i] = 0x09ef;
					break;	
				default:
					a[i] = ch;
			}
			i ++;
		}//  end if('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || 0x09e6 <= ch && ch <= 0x09ef)
	}
	return 0;
}