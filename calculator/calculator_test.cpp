#include "pch.h"
#include "..//calculator.cpp"
Calculator calc;

TEST(calculation_test, Addition) {
	std::string expr = "5+19";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, 24);
}

TEST(calculation_test, Substraction) {
	std::string expr = "5-1";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, 4);
}

TEST(calculation_test, Multiplication) {
	std::string expr = "5*10";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, 50);
}

TEST(calculation_test, Division) {
	std::string expr = "10/4";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, 2.5);
}

TEST(calculation_test, ExpressionWithDouble) {
	std::string expr = "1.2/0.3";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, 4.0);
}

TEST(calculation_test, ExpressionWithParentheses1) {
	std::string expr = "5*(10-4)";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, 30);

	expr = "(10-4)/3";
	calc.setExpression(expr);
	result = calc.calculation();
	EXPECT_EQ(result, 2);
}

TEST(calculation_test, ExpressionWithNegativeNumbers1) {
	std::string expr = "6*(-2)";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, -12);
}

TEST(calculation_test, ExpressionWithNegativeNumbers2) {
	std::string expr = "-3*5";
	calc.setExpression(expr);
	double result = calc.calculation();
	EXPECT_EQ(result, -15);
}

TEST(expressionIsCorresct_test, CorrectExpression) {
	std::string expr = "3+4*(-3)/3";
	calc.setExpression(expr);
	bool result = calc.expressionIsCorrect();
	EXPECT_TRUE(result);
}

TEST(expressionIsCorresct_test, InvalidCharacters) {
	std::string expr = "a+b";
	calc.setExpression(expr);
	bool result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);
}

TEST(expressionIsCorresct_test, OperatorsAtStartOrEnd) {
	std::string expr = "+2-3";
	calc.setExpression(expr);
	bool result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "2-3+";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

}

TEST(expressionIsCorresct_test, ConsecutiveOperators) {
	std::string expr = "2++3";
	calc.setExpression(expr);
	bool result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "2--3";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "2**3";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "2//3";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);
}

TEST(expressionIsCorresct_test, IncorrectMinus) {
	std::string expr = "2+-3";
	calc.setExpression(expr);
	bool result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "2*-3";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "2/-3";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);
}

TEST(expressionIsCorresct_test, IncorrectParentheses) {
	std::string expr = "(3+4";
	calc.setExpression(expr);
	bool result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "3+4)";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "(3+)";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "(+3)";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "()";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "((3+4)";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "(3+4))";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = "(3+4)(";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

	expr = ")3+4(";
	calc.setExpression(expr);
	result = calc.expressionIsCorrect();
	EXPECT_FALSE(result);

}