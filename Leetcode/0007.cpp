int reverse(int x){
    int c[10] = {0}, k = 0;             //宣告回傳的數字
    while(x){                           //x=0時迴圈停止
        c[k++] = x % 10;                //陣列反向記錄每一位數
        x /= 10;                        //迴圈每做一次x少一位
    }
    
    long long res = 0;                  //宣告輸出
    for(int i = 0; i < k; i++)
        res = res * 10 + c[i];          //計算總合
    
    if(res > 2147483647 || res < -2147483648)
        return 0;                       //如果溢位就回傳0
    return res;
}

