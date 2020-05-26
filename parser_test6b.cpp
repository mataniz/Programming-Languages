/*    
  Unit tests for HW07 - Part 2
*/

#include "gtest/gtest.h"

#include "Parser.h"



// Check eval -----------------------------------------------
// HW 06
TEST(eval_hw6, 0){
  Parser p;
  EXPECT_EQ(p.parse("5"), true);
  EXPECT_EQ(p.eval(), 5);
}

TEST(eval_hw6, 1){
  Parser p;
  EXPECT_EQ(p.parse("5+6"), true);
  EXPECT_EQ(p.eval(), 11);
}

TEST(eval_hw6, 2){
  Parser p;
  EXPECT_EQ(p.parse("5+1-2"), true);
  EXPECT_EQ(p.eval(), 4);
}

TEST(eval_hw6, 3){
  Parser p;
  EXPECT_EQ(p.parse("5+2-(5+1)"), true);
  EXPECT_EQ(p.eval(), 1);
}

TEST(eval_hw6, 4){
  Parser p;
  EXPECT_EQ(p.parse("5*2-(5+1)"), true);
  EXPECT_EQ(p.eval(), 4);
}

TEST(eval_hw6, 5){
  Parser p;
  EXPECT_EQ(p.parse("1+2*3+4"), true);
  EXPECT_EQ(p.eval(), 11);
}

TEST(eval_hw6, 6){
  Parser p;
  EXPECT_EQ(p.parse("1*2*3*4"), true);
  EXPECT_EQ(p.eval(), 24);
}

TEST(eval_hw6, 7){
  Parser p;
  EXPECT_EQ(p.parse("2*3*4 + 1"), true);
  EXPECT_EQ(p.eval(), 25);
}

TEST(eval_hw6, 8){
  Parser p;
  EXPECT_EQ(p.parse("(1+3) * (2*3)"), true);
  EXPECT_EQ(p.eval(), 24);
}

TEST(eval_hw6, 9){
  Parser p;
  EXPECT_EQ(p.parse("24/3"), true);
  EXPECT_EQ(p.eval(), 8);
}

TEST(eval_hw6, 10){
  Parser p;
  EXPECT_EQ(p.parse("(2*3) /  3 + 1"), true);
  EXPECT_EQ(p.eval(), 3);
}

// Check eval -----------------------------------------------
// HW 07
TEST(eval_hw7, 0){
  Parser p;
  EXPECT_EQ(p.parse("5 ^ 2"), true);
  EXPECT_EQ(p.eval(), 25);
}

TEST(eval_hw7, 1){
  Parser p;
  EXPECT_EQ(p.parse("5 + 5 ^ 2 - 1"), true);
  EXPECT_EQ(p.eval(), 29);
}

TEST(eval_hw7, 2){
  Parser p;
  EXPECT_EQ(p.parse("5 + 5 ^ (2 - 1)"), true);
  EXPECT_EQ(p.eval(), 10);
}

TEST(eval_hw7, 3){
  Parser p;
  EXPECT_EQ(p.parse("11 % 10"), true);
  EXPECT_EQ(p.eval(), 1);
}

TEST(eval_hw7, 4){
  Parser p;
  EXPECT_EQ(p.parse("1 + 14 % 3 + 1"), true);
  EXPECT_EQ(p.eval(), 4);
}

TEST(eval_hw7, 5){
  Parser p;
  EXPECT_EQ(p.parse("(1 + 14) % (3 + 1)"), true);
  EXPECT_EQ(p.eval(), 3);
}

// Check parse -----------------------------------------------
// HW 08
TEST(parse_hw8_assignment, 1){
  Parser p;
  EXPECT_EQ(p.parse("a = 1"), true);
}

TEST(parse_hw8_assignment, 2){
  Parser p;
  EXPECT_EQ(p.parse("a = 15"), true);
}

TEST(parse_hw8_assignment, 3){
  Parser p;
  EXPECT_EQ(p.parse("aa = 1"), true);
}

TEST(parse_hw8_assignment, 4){
  Parser p;
  EXPECT_EQ(p.parse("var = 34 + 1"), true);
}

TEST(parse_hw8_assignment, 5){
  Parser p;
  EXPECT_EQ(p.parse("3 + (z = 4) + 1"), true);
}

TEST(parse_hw8_assignment, 6){
  Parser p;
  EXPECT_EQ(p.parse("3 + z = 4 + 1"), false);
}

TEST(parse_hw8_assignment, 7){
  Parser p;
  EXPECT_EQ(p.parse("3 + a = 4 - 1"), false);
}

// Check variables -----------------------------------------------

TEST(parse_hw8_variable, 1){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("a"), 3);
}

TEST(parse_hw8_variable, 2){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("a = 5"), 5);
  EXPECT_EQ(p.eval("a"), 5);
}

TEST(parse_hw8_variable, 3){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("b = 5"), 5);
  EXPECT_EQ(p.eval("a + b"), 8);
}

TEST(parse_hw8_variable, 4){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("b = 5"), 5);
  EXPECT_EQ(p.eval("a = a + 1"), 4);
  EXPECT_EQ(p.eval("b = b + 1"), 6);
  EXPECT_EQ(p.eval("a * b"), 24);
}

TEST(parse_hw8_variable, 5){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("5 * (b = 2) - 1"), 9);
}

TEST(parse_hw8_variable, old_parse_eval){
  Parser p;
  EXPECT_EQ(p.eval("a = 30"), 30);
  EXPECT_EQ(p.parse("a = 3"), true);
  EXPECT_EQ(p.eval("a"), 30);
  EXPECT_EQ(p.parse("a = 3"), true);
  EXPECT_EQ(p.eval(), 3);
  EXPECT_EQ(p.eval("a"), 3);
}

// Check clear -----------------------------------------------
TEST(parse_hw8_varClear, 1){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("b = 5"), 5);
  EXPECT_EQ(p.eval("a + b"), 8);
  p.varClear();
  EXPECT_NE(p.eval("a + b"), 8);
}

// Check dump
TEST(parse_hw8_varDump, 1){
  Parser p;
  EXPECT_EQ(p.eval("a = 3"), 3);
  EXPECT_EQ(p.eval("b = 5"), 5);
  p.varDump();
}