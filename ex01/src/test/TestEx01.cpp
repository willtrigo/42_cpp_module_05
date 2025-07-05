/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestEx01.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:29:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/05 20:41:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/bureaucrat/Bureaucrat.hpp"
#include "core/form/Form.hpp"
#include "test/TestEx01.hpp"
#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

static void testBasicFormFunctionality();
static void testInvalidFormConstruction();
static void testSuccessfulFormSigning();
// static void testCopyOperations();

void runAllEx01Tests() {
	testBasicFormFunctionality();
  testInvalidFormConstruction();
  testSuccessfulFormSigning();
  // testCopyOperations();
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

// static void testCopyOperations() {
//   testHelperPrintSection("Copy Operations");
//
//   try {
//     Bureaucrat original("Original", 42);
//     std::cout << "Original: " << original << std::endl;
//
//     std::cout << std::endl;
//     Bureaucrat copy(original);
//     std::cout << "Copy constructed: " << copy << std::endl;
//
//     std::cout << std::endl;
//     Bureaucrat assigned("Temporary", 111);
//     std::cout << "Before assignment: " << assigned << std::endl;
// 		assigned = original;
// 		std::cout << "After assignment: " << assigned << std::endl;
//
//     std::cout << std::endl;
//     original.incrementGrade();
// 		std::cout << "After modifying original:" << std::endl;
// 		std::cout << "  Original: " << original << std::endl;
// 		std::cout << "  Copy: " << copy << std::endl;
// 		std::cout << "  Assigned: " << assigned << std::endl;
//   } catch (const std::exception& e) {
//     testHelperLog(ORANGE, "Expection caught:");
//     testHelperLog(RED, e.what());
//   }
// }
