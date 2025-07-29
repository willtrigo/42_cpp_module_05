/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InternTests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:37:30 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 19:12:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/intern/Intern.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/domain/InternTests.hpp"
#include "interfaces/testing/TestRunner.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>

InternTests::InternTests(const InternTests&) {}

InternTests::~InternTests() {}

InternTests& InternTests::operator=(const InternTests&) {
  throw std::runtime_error("Copying of InternTests is not allowed");
}

void InternTests::createTestSuite() {
  InternTests::testValidForm();
  InternTests::testInvalidForm();
}

void InternTests::testValidForm() {
  TestRunner::PrintSection(ORANGE, ORANGE, true, "Intern Valid Form");

  try {
    Intern intern;
    std::auto_ptr<AForm> formPresidential(intern.makeForm("presidential pardon", "Will Trigo"));
    FormPrinter::print(std::cout, *formPresidential);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    Intern intern;
    std::auto_ptr<AForm> formRobotomy(intern.makeForm("robotomy request", "Staff"));
    FormPrinter::print(std::cout, *formRobotomy);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    Intern intern;
    std::auto_ptr<AForm> formShrunbbery(intern.makeForm("shrubbery creation", "home"));
    FormPrinter::print(std::cout, *formShrunbbery);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void InternTests::testInvalidForm() {
  TestRunner::PrintSection(ORANGE, ORANGE, true, "Intern Invalid Form");

  try {
    Intern intern;
    std::auto_ptr<AForm> formPresidential(intern.makeForm("doom day", "Staff"));
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Intern::InvalidFormException& e) {
    StreamWriter::print(ORANGE, "Correctly caught InvalidFormException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
