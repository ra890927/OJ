

int romanToInt(char * s){
    int ret = 0;                    //跑计
	int pre = 0;
	int res = 0;
	int num[26] = {0};              //魁–才腹计
	num['I' - 'A'] = 1;
	num['V' - 'A'] = 5;
	num['X' - 'A'] = 10;
	num['L' - 'A'] = 50;
	num['C' - 'A'] = 100;
	num['D' - 'A'] = 500;
	num['M' - 'A'] = 1000;

	while(*s != '\0'){              //sぃ单じ碞磅︽
		res = num[*s - 'A'];        //魁瞷计
		if(pre < res && pre){       //狦玡计!=0瞷计玡
			ret += res - pre;       //碞琌搭猭р玡穝0
			pre = 0;
		}
		else if(pre >= res && pre){ //狦玡计!=0瞷计>=玡
			ret += pre;             //碞琌猭玡计
			pre = res;              //玡计穝瞷计
		}
		else
			pre = res;              //常ぃ琌杠穝玡计

		s++;                     
	}

	return ret + pre;               //程肚⊿Τ玡计┮璶ㄓ
}

