/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:20:38 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 20:10:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/domain/FormTests.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
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
#include <memory>
#include <stdexcept>

FormTests::FormTests(const FormTests&) {}

FormTests::~FormTests() {}

FormTests& FormTests::operator=(const FormTests&) {
  throw std::runtime_error("Copying of FormTests is not allowed");
}

void FormTests::createTestSuite() {
  FormTests::testFormBasicFunctionality();
  FormTests::testFormCopyOperations();
}

void FormTests::testFormBasicFunctionality() {
  TestRunner::PrintSection(CYAN, CYAN, true, "Form Basic Functionality");

  try {
    StreamWriter::print(GREEN, "Created form:");
    std::auto_ptr<AForm> form_pardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *form_pardon);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(BLUE, "Created form:");
    std::auto_ptr<AForm> form_robotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> form_shrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery);
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
    std::auto_ptr<AForm> form_pardon_original(new PresidentialPardonForm("Original"));
    FormPrinter::print(std::cout, *form_pardon_original);

    StreamWriter::print(PURPLE, "Created form assigment:");
    std::auto_ptr<AForm> form_pardon_assignment(form_pardon_original->clone());
    FormPrinter::print(std::cout, *form_pardon_assignment);

    StreamWriter::print(ORANGE, "After change the original:");
    form_pardon_original->beSigned(randomDude);

    StreamWriter::print(GREEN, "Form original:");
    FormPrinter::print(std::cout, *form_pardon_original);

    StreamWriter::print(PURPLE, "Form assigment:");
    FormPrinter::print(std::cout, *form_pardon_assignment);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    Bureaucrat randomDude("Random Dude", 1);
    StreamWriter::print(BLUE, "Created form original:");
    std::auto_ptr<AForm> form_robotomy_original(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *form_robotomy_original);

    StreamWriter::print(PURPLE, "Created form assigment:");
    std::auto_ptr<AForm> form_robotomy_assignment(form_robotomy_original->clone());
    FormPrinter::print(std::cout, *form_robotomy_assignment);

    StreamWriter::print(ORANGE, "After change the original:");
    form_robotomy_original->beSigned(randomDude);

    StreamWriter::print(BLUE, "Form original:");
    FormPrinter::print(std::cout, *form_robotomy_original);

    StreamWriter::print(PURPLE, "Form assigment:");
    FormPrinter::print(std::cout, *form_robotomy_assignment);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    Bureaucrat randomDude("Random Dude", 1);
    StreamWriter::print(YELLOW, "Created form original:");
    std::auto_ptr<AForm> form_shrunbbery_original(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *form_shrunbbery_original);

    StreamWriter::print(PURPLE, "Created form assigment:");
    std::auto_ptr<AForm> form_shrunbbery_assignment(form_shrunbbery_original->clone());
    FormPrinter::print(std::cout, *form_shrunbbery_assignment);

    StreamWriter::print(ORANGE, "After change the original:");
    form_shrunbbery_original->beSigned(randomDude);

    StreamWriter::print(YELLOW, "Form original:");
    FormPrinter::print(std::cout, *form_shrunbbery_original);

    StreamWriter::print(PURPLE, "Form assigment:");
    FormPrinter::print(std::cout, *form_shrunbbery_assignment);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
