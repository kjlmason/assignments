//calculator.js			Written by Kyle Mason
//Javascript file for calculator.html

SecondNumber = "0";
FirstNumber = "0";
MathOp = "";


//Buttons
function GetNum(x)
{
    if (eval(SecondNumber) == 0)
        SecondNumber = x;
    else
        SecondNumber = SecondNumber + x;

    document.Calculator.screen.value = SecondNumber;
}


//Clear Button
function Clear()
{
    FirstNumber = "0"
    MathOp = ""
    SecondNumber = "0"

    document.Calculator.screen.value = SecondNumber;
}


//Math Operation
function DoMath(x)
{
    MathOp = x
    FirstNumber = SecondNumber;
    SecondNumber = "0";

    document.Calculator.screen.value = SecondNumber;
}


//Equals
function Calculate()
{ 
    if (MathOp == "*")
        SecondNumber = eval("FirstNumber * SecondNumber");
    else if (MathOp == "/")
        SecondNumber = eval("FirstNumber / SecondNumber");
    else if (MathOp == "+")
        SecondNumber = eval(FirstNumber) + eval(SecondNumber);
    else if (MathOp == "-")
        SecondNumber = eval("FirstNumber - SecondNumber");

    MathOp = "";
    FirstNumber = "0";

    document.Calculator.screen.value = SecondNumber;
}

//Refresh on Change
function Refresh()
{
    SecondNumber = document.Calculator.screen.value;
    SecondNumber = "" + parseFloat(SecondNumber);
    if (SecondNumber.indexOf("NaN") != -1)
        Clear();

    document.Calculator.screen.value = SecondNumber;
}