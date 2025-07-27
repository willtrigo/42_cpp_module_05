/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 14:14:11 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 15:21:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/domain/FormTests.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/Form.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestRunner.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

FormTests::FormTests(const FormTests&) {}

FormTests::~FormTests() {}

FormTests& FormTests::operator=(const FormTests&) {
  throw std::runtime_error("Copying of FormTests is not allowed");
}

void FormTests::createTestSuite() {
  FormTests::testFormBasicFunctionality();
  FormTests::testFormCopyOperations();
  FormTests::testFormBoundaryConditions();
  FormTests::testInvalidFormConstruction();
}

void FormTests::testFormBasicFunctionality() {
  TestRunner::PrintSection(CYAN, CYAN, true, "Form Basic Functionality");

  try {
    StreamWriter::print(GREEN, "Created form:");
    Form taxForm("Tax Form", 50, 25);
    FormPrinter::print(std::cout, taxForm);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void FormTests::testInvalidFormConstruction() {
  TestRunner::PrintSection(CYAN, CYAN, true, "Invalid Form Construction");

  try {
    StreamWriter::print(RESET, "Attempting to create form with grade sign 0...");
    Form invalidForm("Invalid Sign", 0, 50);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(RESET, "Attempting to create form with grade execute 0...");
    Form invalidForm("Invalid Sign", 50, 0);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(RESET, "Attempting to create form with grade sign 151...");
    Form invalidForm("Invalid Sign", 151, 50);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(RESET, "Attempting to create form with grade execute 151...");
    Form invalidForm("Invalid Sign", 50, 151);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void FormTests::testFormBoundaryConditions() {
  TestRunner::PrintSection(CYAN, CYAN, true, "Form Boundary Conditions");

  try {
    StreamWriter::print(RESET, "Created form with minimum grade:");
    Form minForm("Min Form", 1, 1);
    FormPrinter::print(std::cout, minForm);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(RESET, "Created form with maximum grade:");
    Form maxForm("Min Form", 150, 150);
    FormPrinter::print(std::cout, maxForm);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void FormTests::testFormCopyOperations() {
  TestRunner::PrintSection(CYAN, CYAN, true, "Form Copy Operations");

  try {
    Bureaucrat randomDude("Random Dude", 1);
    StreamWriter::print(GREEN, "Created form original:");
    Form formOriginal("Original Form", 42, 42);
    FormPrinter::print(std::cout, formOriginal);

    StreamWriter::print(BLUE, "Created form copy:");
    Form formCopy(formOriginal);
    FormPrinter::print(std::cout, formCopy);

    StreamWriter::print(PURPLE, "Created form assigment:");
    Form formAssigned("Temp Form", 1, 1);
    FormPrinter::print(std::cout, formAssigned);
    StreamWriter::print(ORANGE, "After assigment:");
    formAssigned = formOriginal;
    FormPrinter::print(std::cout, formAssigned);

    StreamWriter::print(ORANGE, "After change the original:");
    formOriginal.beSigned(randomDude);

    StreamWriter::print(GREEN, "Form original:");
    FormPrinter::print(std::cout, formOriginal);

    StreamWriter::print(BLUE, "Form copy:");
    FormPrinter::print(std::cout, formCopy);

    StreamWriter::print(PURPLE, "Form assigment:");
    FormPrinter::print(std::cout, formCopy);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
