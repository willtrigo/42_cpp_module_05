/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestRunner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:01:19 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/25 17:45:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestRunner.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/domain/BureaucratTests.hpp"
#include "interfaces/testing/domain/FormTests.hpp"
#include <stdexcept>

TestRunner::TestRunner() {}

TestRunner::TestRunner(const TestRunner&) {}

TestRunner::~TestRunner() {}

TestRunner& TestRunner::operator=(const TestRunner&) {
  throw std::runtime_error("Copying of TestRunner is not allowed");
}

void TestRunner::runAllTests() {
  TestRunner::PrintSection(GREEN, RESET, false, "BUREAUCRAT TESTING SUITE");

  BureaucratTests::createTestSuite();
  FormTests::createTestSuite();

  TestRunner::PrintSection(GREEN, RESET, true, "ALL TESTS COMPLETED");
}

void TestRunner::PrintSection(
  StrColor defaultColor,
  StrColor strColor,
  bool isJumpLine,
  const std::string& str) {
  if (isJumpLine) {
    StreamWriter::print(defaultColor, "\n" + std::string(LINE_SIZE, '='));
  } else {
    StreamWriter::print(defaultColor, std::string(LINE_SIZE, '='));
  }

  if (strColor != RESET) {
    StreamWriter::print(strColor, "TEST: " + str);
  } else {
    StreamWriter::print(defaultColor, str);
  }

  StreamWriter::print(defaultColor, std::string(LINE_SIZE, '='));
}
