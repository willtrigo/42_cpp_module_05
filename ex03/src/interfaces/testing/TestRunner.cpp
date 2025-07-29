/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestRunner.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:37:15 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:06:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestRunner.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/domain/BureaucratTests.hpp"
#include "interfaces/testing/domain/FormTests.hpp"
#include "interfaces/testing/integration/IntegrationTests.hpp"
#include <stdexcept>

TestRunner::TestRunner(const TestRunner&) {}

TestRunner::~TestRunner() {}

TestRunner& TestRunner::operator=(const TestRunner&) {
  throw std::runtime_error("Copying of TestRunner is not allowed");
}

void TestRunner::runAllTests() {
  TestRunner::PrintSection(GREEN, RESET, false, "BUREAUCRAT TESTING SUITE");

  BureaucratTests::createTestSuite();
  FormTests::createTestSuite();
  IntegrationTests::createTestSuite();

  TestRunner::PrintSection(GREEN, RESET, true, "ALL TESTS COMPLETED");
}

void TestRunner::PrintSection(
  StrColor defaultColor,
  StrColor strColor,
  bool isJumpLine,
  const std::string& str) {
  if (isJumpLine) {
    StreamWriter::print(defaultColor, "\n" + std::string(TestRunner::LINE_SIZE, '='));
  } else {
    StreamWriter::print(defaultColor, std::string(TestRunner::LINE_SIZE, '='));
  }

  if (strColor != RESET) {
    StreamWriter::print(strColor, "TEST: " + str);
  } else {
    StreamWriter::print(defaultColor, str);
  }

  StreamWriter::print(defaultColor, std::string(TestRunner::LINE_SIZE, '='));
}

void TestRunner::PrintSeparator() {
  StreamWriter::print(RESET, "");
  StreamWriter::print(WHITE, std::string(TestRunner::LINE_SIZE, '='));
  StreamWriter::print(RESET, "");
}
