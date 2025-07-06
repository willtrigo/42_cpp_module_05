/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestEx01.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:29:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/06 12:19:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/bureaucrat/Bureaucrat.hpp"
#include "core/form/Form.hpp"
#include "test/TestEx01.hpp"
#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"
#include <exception>
#include <iostream>

static void testBasicFormFunctionality();
static void testInvalidFormConstruction();
static void testSuccessfulFormSigning();
static void testInsufficientGradeToSigning();
static void testAlreadySignedForm();
static void testFormBoundaryConditions();

void runAllEx01Tests() {
	testBasicFormFunctionality();
  testInvalidFormConstruction();
  testSuccessfulFormSigning();
  testInsufficientGradeToSigning();
  testAlreadySignedForm();
  testFormBoundaryConditions();
}

static void testBasicFormFunctionality() {
	testHelperPrintSection(PURPLE, "Basic Form Functionality");

	try {
    Form taxForm("Tax Form", 50, 25);
    std::cout << "Created " << taxForm << std::endl << std::endl;
    std::cout << "Func getName: " << taxForm.getName() << std::endl;
    std::cout << "Func getGradeToSign: " << taxForm.getGradeToSign() << std::endl;
    std::cout << "Func getGradeToExecute: " << taxForm.getGradeToExecute() << std::endl;
    std::cout << "Func getIsSigned: " << taxForm.isSigned() << std::endl;
	} catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
	}
}


static void testInvalidFormConstruction() {
  testHelperPrintSection(PURPLE, "Invalid Form Construction");

  try {
    testHelperLog(RESET, "Attempting to create form with sign grade 0...");
    Form invalidForm("Invalid Sign", 0, 50);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Form::GradeTooHighException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooHighException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }

  std::cout << std::endl;

  try {
    testHelperLog(RESET, "Attempting to create form with execute grade 0...");
    Form invalidForm("Invalid Sign", 50, 0);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Form::GradeTooHighException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooHighException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }

  std::cout << std::endl;

  try {
    testHelperLog(RESET, "Attempting to create form with sign grade 151...");
    Form invalidForm("Invalid Sign", 151, 50);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Form::GradeTooLowException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooLowException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }

  std::cout << std::endl;

  try {
    testHelperLog(RESET, "Attempting to create form with execute grade 151...");
    Form invalidForm("Invalid Sign", 50, 151);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Form::GradeTooLowException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooLowhException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}

static void testSuccessfulFormSigning() {
  testHelperPrintSection(PURPLE, "Successful Form Signing");

  try {
    Form importantForm("Important Document", 100, 42);
    Bureaucrat manager("Manager", 42);

    std::cout << "Before signing:" << std::endl;
    std::cout << "  " << importantForm << std::endl;
    std::cout << "  " << manager << std::endl;
    std::cout << std::endl;

    importantForm.beSigned(manager);
    std::cout << std::endl;

    std::cout << "After signing:" << std::endl;
    std::cout << "  " << importantForm << std::endl;
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}

static void testInsufficientGradeToSigning() {
  testHelperPrintSection(PURPLE, "Insufficient Grade to Signing");

  try {
    Form importantForm("Important Document", 42, 2);
    Bureaucrat intern("Intern", 145);

    std::cout << "Before signing:" << std::endl;
    std::cout << "  " << importantForm << std::endl;
    std::cout << "  " << intern << std::endl;
    std::cout << std::endl;

    importantForm.beSigned(intern);

    std::cout << std::endl;

    std::cout << "After signing:" << std::endl;
    std::cout << "  " << importantForm << std::endl;
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}

static void testAlreadySignedForm() {
  testHelperPrintSection(PURPLE, "Already Signed Form");

  try {
    Form contract("Contract", 42, 30);
    Bureaucrat supervisor("supervisor", 42);
    Bureaucrat director("Director", 21);

    std::cout << "Initial state:" << std::endl;
    std::cout << "  " << contract << std::endl;

    std::cout << std::endl;

    contract.beSigned(supervisor);

    std::cout << std::endl;

    std::cout << "After first signing:" << std::endl;
    std::cout << "  " << contract << std::endl;

    std::cout << std::endl;

    std::cout << "Attempting second signing..." << std::endl;
    contract.beSigned(director);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Form::FormSignedException& e) {
    testHelperLog(ORANGE, "Correctly caught FormSignedException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}

static void testFormBoundaryConditions() {
  testHelperPrintSection(PURPLE, "Form Boundary Conditions");

  try {
    Form minForm("Min Form", 1, 1);
    std::cout << "Created form with minimum grades: " << minForm << std::endl;

    std::cout << std::endl;

    Form maxForm("Max Form", 150, 150);
    std::cout << "Created form with maximum grades: " << maxForm << std::endl;

    std::cout << std::endl;

    Bureaucrat exactGradeToTest("Exact Grade To Test", 42);
    Form normalForm("Normal Form", 42, 42);

    std::cout << "Testing exact grade boundary:" << std::endl;
    std::cout << "  " << exactGradeToTest << std::endl;
    std::cout << "  " << normalForm << std::endl;

    std::cout << std::endl;

    normalForm.beSigned(exactGradeToTest);

    std::cout << std::endl;

    std::cout << "After signing:" << std::endl;
    std::cout << "  " << normalForm << std::endl;
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}
