/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:20:38 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/25 23:50:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/domain/FormTests.hpp"
#include "domain/models/form/AForm.hpp"
#include "domain/models/form/creations/shrubbery/ShrubberyCreationForm.hpp"
#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestRunner.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

FormTests::FormTests() {}

FormTests::FormTests(const FormTests&) {}

FormTests::~FormTests() {}

FormTests& FormTests::operator=(const FormTests&) {
  throw std::runtime_error("Copying of FormTests is not allowed");
}

void FormTests::createTestSuite() {
  FormTests::testBasicFunctionality();
}

void FormTests::testBasicFunctionality() {
  TestRunner::PrintSection(CYAN, CYAN, true, "Form Basic Functionality");

  try {
    StreamWriter::print(GREEN, "Created form:");
    AForm *form_pardon = new PresidentialPardonForm("Will Trigo");
    FormPrinter::print(std::cout, *form_pardon);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(BLUE, "Created form:");
    AForm *form_robotomy = new RobotomyRequestForm("Staff");
    FormPrinter::print(std::cout, *form_robotomy);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(YELLOW, "Created form:");
    AForm *form_shrunbbery = new ShrubberyCreationForm("home");
    FormPrinter::print(std::cout, *form_shrunbbery);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
