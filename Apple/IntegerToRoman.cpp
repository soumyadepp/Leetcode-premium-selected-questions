class Solution {
public:
string solve(int n){
        switch(n){
            case 1:
                return "I";
                break;
            case 4:
                return "IV";    
            case 5:
                return "V";
            case 9:
                return "IX";
            case 10:
                return "X";
            case 40:
                return "XL";
            case 50:
                return "L";
            case 90:
                return "XC";
            case 100:
                return "C";
            case 400:
                return "CD";
            case 500:
                return "D";
            case 900:
                return "CM";
            case 1000:
                return "M";
            default:
                return "";
        }
    }
    int getRange(int n){
        if(n>=1000){
            return 1000;
        }else if(n>=900 and n<1000){
            return 900;
        }else if(n<900 and n>=500){
            return 500;
        }
        else if(n>=400 and n<500){
            return 400;
        }else if(n<400 and n>=100){
            return 100;
        }else if (n<100 and n>=90){
            return 90;
        }
        else if(n<90 and n>=50){
            return 50;
        }else if (n<50 and n>=40){
            return 40;
        }else if(n<40 and n>=10){
            return 10;
        }else if(n>=9 and n<10){
            return 9;
        }else if(n>=5 and n<9){
            return 5;
        }
        else if(n>=4 and n<5){
            return 4;
        }
        else{
            return 1;
        }
    }
    string intToRoman(int num) {
       string res="";
        while(num>=1){
            int base=getRange(num);
            int quo=num/base;
            int rem=num%base;
            
            num=rem;
            while(quo--){
                res+=solve(base);
            }
        }
        return res;
    }
};
