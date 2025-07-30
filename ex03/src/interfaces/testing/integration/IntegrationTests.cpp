/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegrationTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:38:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/30 16:40:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/integration/IntegrationTests.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include "domain/models/form/creations/shrubbery/ShrubberyCreationForm.hpp"
#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestRunner.hpp"
#include <exception>
#include <iostream>
#include <memory>
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
  IntegrationTests::testInsufficientGradeToExecuteForm();
  IntegrationTests::testAlreadyExecuteForm();
  IntegrationTests::testExecuteWithoutSigningForm();
}

void IntegrationTests::testSuccessfulSignedExecuteForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Succesful Form signed and executed");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);

    boss.signForm(*formPardon);
    FormPrinter::print(std::cout, *formPardon);

    formPardon->execute(boss);
    FormPrinter::print(std::cout, *formPardon);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->beSigned(boss);
    FormPrinter::print(std::cout, *formRobotomy);

    while (!formRobotomy->isExecuted()) {
      formRobotomy->execute(boss);
      FormPrinter::print(std::cout, *formRobotomy);
    }
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    StreamWriter::print(PURPLE, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->beSigned(boss);
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->execute(boss);
    FormPrinter::print(std::cout, *formShrunbbery);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void IntegrationTests::testInsufficientGradeToSigingForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Insufficient Grade To Signing");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 150);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);

    formPardon->beSigned(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 150);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->beSigned(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 150);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(PURPLE, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->beSigned(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::GradeTooLowException& e) {
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
    Bureaucrat randomDude("Random Dude", 25);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);

    formPardon->beSigned(randomDude);
    FormPrinter::print(std::cout, *formPardon);

    formPardon->beSigned(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 72);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->beSigned(randomDude);
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->beSigned(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 145);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(PURPLE, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->beSigned(randomDude);
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->beSigned(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void IntegrationTests::testInsufficientGradeToExecuteForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Insufficient Grade To Signing");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 6);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);

    formPardon->beSigned(randomDude);
    FormPrinter::print(std::cout, *formPardon);

    formPardon->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 150);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->beSigned(randomDude);
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 150);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(PURPLE, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->beSigned(randomDude);
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void IntegrationTests::testAlreadyExecuteForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Already Executed Form");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 5);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);

    formPardon->beSigned(randomDude);
    FormPrinter::print(std::cout, *formPardon);

    formPardon->execute(randomDude);
    FormPrinter::print(std::cout, *formPardon);

    formPardon->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormExecutedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormExecutedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 45);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->beSigned(randomDude);
    FormPrinter::print(std::cout, *formRobotomy);

    while (!formRobotomy->isExecuted()) {
      formRobotomy->execute(randomDude);
      FormPrinter::print(std::cout, *formRobotomy);
    }

    formRobotomy->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormExecutedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormExecutedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 137);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(PURPLE, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->beSigned(randomDude);
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->execute(randomDude);
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormExecutedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormExecutedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void IntegrationTests::testExecuteWithoutSigningForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Executed Without Signing Form");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 5);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);

    formPardon->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormNotSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormNotSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 45);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);

    formRobotomy->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormNotSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormNotSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 137);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(PURPLE, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);

    formShrunbbery->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormNotSignedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormNotSignedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
