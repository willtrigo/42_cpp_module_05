/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestEx01.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:29:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/05 10:55:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "core/bureaucrat/Bureaucrat.hpp"
#include "core/form/Form.hpp"
#include "test/TestEx01.hpp"
#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

static void testBasicFormFunctionality();
static void testInvalidFormConstruction();
// static void testBoundaryConditions();
// static void testCopyOperations();

void runAllEx01Tests() {
	testBasicFormFunctionality();
  testInvalidFormConstruction();
  // testBoundaryConditions();
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

}

// static void testBoundaryConditions() {
//   testHelperPrintSection("Boundary Conditions");
//
//   try {
//     Bureaucrat topBureaucrat("The Boss", 1);
//     std::cout << "Created bureaucrat: " << topBureaucrat << std::endl;
//     testHelperLog(RESET, "Attempting to incrementgrade 1...");
//     topBureaucrat.incrementGrade();
//     testHelperLog(RED, "Error: should have throw exception");
//   } catch (const Bureaucrat::GradeTooHighException& e) {
//     testHelperLog(ORANGE, "Correctly caught GradeTooHighException:");
//     testHelperLog(RED, e.what());
//   } catch (const std::exception& e) {
//     testHelperLog(ORANGE, "Caught unexpected exception:");
//     testHelperLog(RED, e.what());
//   }
//
//   std::cout << std::endl;
//
//   try {
//     Bureaucrat bottomBureaucrat("Intern", 150);
//     std::cout << "Created bureaucrat: " << bottomBureaucrat << std::endl;
//     testHelperLog(RESET, "Attempting to decrement 150...");
//     bottomBureaucrat.decrementGrade();
//     testHelperLog(RED, "Error: should have throw exception");
//   } catch (const Bureaucrat::GradeTooLowException& e) {
//     testHelperLog(ORANGE, "Correctly caught GradeTooLowException:");
//     testHelperLog(RED, e.what());
//   } catch (const std::exception& e) {
//     testHelperLog(ORANGE, "Caught unexpected exception:");
//     testHelperLog(RED, e.what());
//   }
// }
//
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
