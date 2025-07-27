/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormTests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:20:38 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:57:03 by dande-je         ###   ########.fr       */
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
    std::auto_ptr<AForm> formPardon(new PresidentialPardonForm("Will Trigo"));
    FormPrinter::print(std::cout, *formPardon);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(BLUE, "Created form:");
    std::auto_ptr<AForm> formRobotomy(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomy);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    StreamWriter::print(YELLOW, "Created form:");
    std::auto_ptr<AForm> formShrunbbery(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbbery);
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
    std::auto_ptr<AForm> formPardonOriginal(new PresidentialPardonForm("Original"));
    FormPrinter::print(std::cout, *formPardonOriginal);

    StreamWriter::print(PURPLE, "Created form copy:");
    std::auto_ptr<AForm> formPardonCopy(formPardonOriginal->clone());
    FormPrinter::print(std::cout, *formPardonCopy);

    StreamWriter::print(ORANGE, "After change the original:");
    formPardonOriginal->beSigned(randomDude);

    StreamWriter::print(GREEN, "Form original:");
    FormPrinter::print(std::cout, *formPardonOriginal);

    StreamWriter::print(PURPLE, "Form copy:");
    FormPrinter::print(std::cout, *formPardonCopy);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    Bureaucrat randomDude("Random Dude", 1);
    StreamWriter::print(BLUE, "Created form original:");
    std::auto_ptr<AForm> formRobotomyOriginal(new RobotomyRequestForm("Staff"));
    FormPrinter::print(std::cout, *formRobotomyOriginal);

    StreamWriter::print(PURPLE, "Created form copy:");
    std::auto_ptr<AForm> formRobotomyCopy(formRobotomyOriginal->clone());
    FormPrinter::print(std::cout, *formRobotomyCopy);

    StreamWriter::print(ORANGE, "After change the original:");
    formRobotomyOriginal->beSigned(randomDude);

    StreamWriter::print(BLUE, "Form original:");
    FormPrinter::print(std::cout, *formRobotomyOriginal);

    StreamWriter::print(PURPLE, "Form copy:");
    FormPrinter::print(std::cout, *formRobotomyCopy);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  TestRunner::PrintSeparator();

  try {
    Bureaucrat randomDude("Random Dude", 1);
    StreamWriter::print(YELLOW, "Created form original:");
    std::auto_ptr<AForm> formShrunbberyOriginal(new ShrubberyCreationForm("home"));
    FormPrinter::print(std::cout, *formShrunbberyOriginal);

    StreamWriter::print(PURPLE, "Created form copy:");
    std::auto_ptr<AForm> formShrunbberyCopy(formShrunbberyOriginal->clone());
    FormPrinter::print(std::cout, *formShrunbberyCopy);

    StreamWriter::print(ORANGE, "After change the original:");
    formShrunbberyOriginal->beSigned(randomDude);

    StreamWriter::print(YELLOW, "Form original:");
    FormPrinter::print(std::cout, *formShrunbberyOriginal);

    StreamWriter::print(PURPLE, "Form copy:");
    FormPrinter::print(std::cout, *formShrunbberyCopy);

  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}
