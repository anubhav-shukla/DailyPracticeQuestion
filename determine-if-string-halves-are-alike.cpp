 bool halvesAreAlike(string s) {
        int n = s.length();
        int half = n/2;
        int num1=0, num2 = 0;
        for (int i=0; i<half; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'|| s[i] == 'A'||s[i] == 'E'||s[i] == 'O'||s[i] == 'I'||s[i] == 'U')
                num1 ++;
            
            if(s[half+i] == 'a' || s[half+i] == 'e' || s[half+i] == 'i'|| s[half+i] == 'o'|| s[half+i] == 'u'|| s[half+i] == 'A'||s[half+i] == 'E'||s[half+i] == 'O'||s[half+i] == 'I'||s[half+i] == 'U')
                num2 ++;
            
        
        }
        
        return num1==num2;
    }