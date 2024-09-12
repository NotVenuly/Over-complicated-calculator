#include <iostream>
#include <cmath>
#include <cctype>


char *Listify(std::string num);
int ListLength(char* maPenis);
int Numberify (int num, char *numberList);


int main(){
    std::string firstNum;
    std::string secondNum;


    char operand;
    char* pFirstList;
    char* pSecondList;
    char input;

    int trueValue1;
    int trueValue2;
    int ans;
    int lengthFirst;
    int lengthSecond;

    while (true){

        std::cout << "Please input a number or press \"X\" to exit the program: ";
        std::cin >> firstNum;
        pFirstList = Listify(firstNum);
        std::cout << "Please input a second number or press \"X\" to exit the program: ";
        std::cin >> secondNum;
        pSecondList = Listify(firstNum);
        std::cout << "What operand do you wish to use: ";
        std::cin >> operand;

        lengthFirst = ListLength(pFirstList);
        lengthSecond = ListLength(pSecondList);

        trueValue1 = Numberify(lengthFirst, pFirstList);
        trueValue2 = Numberify(lengthSecond, pSecondList);


        switch (operand)
        {
            case '+':
                ans = trueValue1 + trueValue2;
                break;

            case '-':
                ans = trueValue1 - trueValue2;
                break;

            case '*':
                ans = trueValue1 * trueValue2;
                break;

            case '/':
                ans = trueValue1 / trueValue2;
                break;
            case '^':
                ans = trueValue1 ^ trueValue2;
                break;
        default:
            std::cout << "Please input a correct command";
            break;
        }

        std::cout << "Answer: " << ans << std::endl;

        std::cout << "Do you wish to continue the program? Y/N";
        std::cin >> input;

        if((char)tolower(input) == 'y'){
            continue;
        }
        else{
            return 0;
        }


    }
    return 0;

}

int Numberify (int num, char *numberList){
    int sum = 0;
    std::cout << "num is this: " << num << std::endl;
    for (int i = num; i >= 0; i--)
    {
        std::cout << "Number at this spot: " << numberList[i] << std::endl;
        if(isdigit(numberList[i])){
            std::cout << "Sum before calculation: " << sum << std::endl;
            // std::cout << "current list spot: " << i << std::endl;
            std::cout << "num is: " << num << std::endl;
            std::cout << "I is: " << i << std::endl;
            std::cout << "this to the power of 10: " << (i) << std::endl;
            sum += numberList[i] * pow(10, (i));
        }

    }
    std::cout << "Sum: " << sum << std::endl;
    return sum;
}

int ListLength(char* maPenis ){
    int num;
    for (num = 0; true; num++){
        if(maPenis[num] == '\n'){
            break;
        }
    }
    return num;
}

char *Listify(std::string num){
    // num.erase(std::remove(num.data(), num.data() + num.size(), ' '), num.data() + num.size());
    int capacity = num.length();
    char* capPointer = new char[capacity + 1];

    int xCount = 0;
    for (int i = 0; i < capacity; i++){
        if(!isdigit(num[i]) && num[i] != 'x'){
            continue;
        }
        if(tolower(num[i]) == 'x'){
            exit(1);
        }
        capPointer[xCount] = num[i];
        xCount++;
    }
    capPointer[capacity + 1] = '\n';

    return capPointer;
}
