bool isPalindrome(int x){
    if(x < 0)                       //特殊判斷，如果x是負的一定不是回文數
        return false;
    
    long long rev = 0, temp = x;    //用long long是因為如果輸入2^31-1會有溢位的情況
    while(temp){                    //如果temp=0迴圈停止
        rev = rev * 10 + temp % 10; //先*10再加上個位數字
        temp /= 10;                 //每做一次temp都少一位
    }
    
    return x == rev;                //回傳如果x=rev就是回文數
}