/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegrationTests.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:20:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 15:41:16 by dande-je         ###   ########.fr       */
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

IntegrationTests::IntegrationTests() {}

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
}

void IntegrationTests::testSuccessfulSignedExecuteForm() {
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Succesful Form signed and executed");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> form_pardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->beSigned(boss);
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->execute(boss);
    FormPrinter::print(std::cout, *form_pardon);
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
    std::auto_ptr<AForm> form_robotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->beSigned(boss);
    FormPrinter::print(std::cout, *form_robotomy);

    while (!form_robotomy->isExecuted()) {
      form_robotomy->execute(boss);
      FormPrinter::print(std::cout, *form_robotomy);
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
    std::auto_ptr<AForm> form_shrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->beSigned(boss);
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->execute(boss);
    FormPrinter::print(std::cout, *form_shrunbbery);
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
    std::auto_ptr<AForm> form_pardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->beSigned(randomDude);
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
    std::auto_ptr<AForm> form_robotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->beSigned(randomDude);
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
    std::auto_ptr<AForm> form_shrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->beSigned(randomDude);
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
    std::auto_ptr<AForm> form_pardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->beSigned(randomDude);
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
    std::auto_ptr<AForm> form_robotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->beSigned(randomDude);
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
    std::auto_ptr<AForm> form_shrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->beSigned(randomDude);
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
    std::auto_ptr<AForm> form_pardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->execute(randomDude);
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
    std::auto_ptr<AForm> form_robotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->execute(randomDude);
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
    std::auto_ptr<AForm> form_shrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->execute(randomDude);
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
  TestRunner::PrintSection(PURPLE, PURPLE, true, "Integration Already Signed Form");

  try {
    StreamWriter::print(CYAN, "Created bureaucrat:");
    Bureaucrat randomDude("Random Dude", 5);
    BureaucratPrinter::print(std::cout, randomDude);

    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> form_pardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->execute(randomDude);
    FormPrinter::print(std::cout, *form_pardon);

    form_pardon->execute(randomDude);
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
    std::auto_ptr<AForm> form_robotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy);

    form_robotomy->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_robotomy);

    while (!form_robotomy->isExecuted()) {
      form_robotomy->execute(randomDude);
      FormPrinter::print(std::cout, *form_robotomy);
    }

    form_robotomy->execute(randomDude);
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
    std::auto_ptr<AForm> form_shrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->beSigned(randomDude);
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->execute(randomDude);
    FormPrinter::print(std::cout, *form_shrunbbery);

    form_shrunbbery->execute(randomDude);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const AForm::AFormExecutedException& e) {
    StreamWriter::print(ORANGE, "Correctly caught AFormExecutedException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
