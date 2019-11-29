

int romanToInt(char * s){
    int ret = 0;                    //�ŧi�ܼ�
	int pre = 0;
	int res = 0;
	int num[26] = {0};              //�����C�ӲŸ����ƭ�
	num['I' - 'A'] = 1;
	num['V' - 'A'] = 5;
	num['X' - 'A'] = 10;
	num['L' - 'A'] = 50;
	num['C' - 'A'] = 100;
	num['D' - 'A'] = 500;
	num['M' - 'A'] = 1000;

	while(*s != '\0'){              //s������Ŧr���N����
		res = num[*s - 'A'];        //�����{�b���ƭ�
		if(pre < res && pre){       //�p�G�e�@�Ӧ��!=0�B�{�b���ƭȤp��e�@��
			ret += res - pre;       //�N�O��k�A�ç�e�@���s��0
			pre = 0;
		}
		else if(pre >= res && pre){ //�p�G�e�@�Ӧ��!=0�B�{�b���ƭ�>=�e�@��
			ret += pre;             //�N�O�[�k�A�[�e�@���
			pre = res;              //�e�@��Ƨ�s���{�b���ƭ�
		}
		else
			pre = res;              //�����O���ܡA��s�e�@���

		s++;                     
	}

	return ret + pre;               //�̫�^�Ǫ��ɭԨS���[�e�@��ơA�ҥH�n�[�^��
}

