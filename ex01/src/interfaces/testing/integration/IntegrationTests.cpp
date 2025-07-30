/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegrationTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:16:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/30 16:31:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/integration/IntegrationTests.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/Form.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestRunner.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

IntegrationTests::IntegrationTests(const IntegrationTests&) {}

IntegrationTests::~IntegrationTests() {}

IntegrationTests& IntegrationTests::operator=(const IntegrationTests&) {
  throw std::runtime_error("Copying of IntegrationTests is not allowed");
}

void IntegrationTests::createTestSuite() {
  IntegrationTests::testSuccessfulSignedExecuteForm();
  IntegrationTests::testInsufficientGradeToSigingForm();
  IntegrationTests::testAlreadySignedForm();
}

void IntegrationTests::testSuccessfulSignedExecuteForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Succesful Form signed and executed");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    StreamWriter::print(GREEN, "Created form:");
    Form importantForm("Important Document", 1, 42);
    FormPrinter::print(std::cout, importantForm);

    boss.signForm(importantForm);
    FormPrinter::print(std::cout, importantForm);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void IntegrationTests::testInsufficientGradeToSigingForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Insufficient Grade To Signing");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat intern("Intern", 145);
    BureaucratPrinter::print(std::cout, intern);

    StreamWriter::print(GREEN, "Created form:");
    Form importantForm("Important Document", 42, 2);
    FormPrinter::print(std::cout, importantForm);

    importantForm.beSigned(intern);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Form::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void IntegrationTests::testAlreadySignedForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Already Signed Form");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    StreamWriter::print(GREEN, "Created form:");
    Form importantForm("Important Document", 100, 42);
    FormPrinter::print(std::cout, importantForm);

    importantForm.beSigned(boss);
    FormPrinter::print(std::cout, importantForm);

    importantForm.beSigned(boss);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Form::FormSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
