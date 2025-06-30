/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestEx00.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:29:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/30 15:35:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/bureaucrat/Bureaucrat.hpp"
#include "test/TestEx00.hpp"
#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

static void testBasicFunctionality();
static void testGradeManipulation();
static void testInvalidConstruction();
static void testBoundaryConditions();
static void testCopyOperations();

void runAllEx00Tests() {
  testHelperLog(GREEN, "=== BUREAUCRAT TESTING SUITE ===");

	testBasicFunctionality();
  testGradeManipulation();
  testInvalidConstruction();
  testBoundaryConditions();
  testCopyOperations();

  testHelperLog(GREEN, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(GREEN, "ALL TESTS COMPLETED");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
}

static void testBasicFunctionality() {
	testHelperPrintSection("Basic Functionality");

	try {
		Bureaucrat daniel("Daniel Trigo", 42);
    std::cout << "Created bureaucrat: " << daniel << std::endl;
    std::cout << "Name: " << daniel.getName() << std::endl;
		std::cout << "Grade: " << daniel.getGrade() << std::endl;

    std::cout << std::endl;

		Bureaucrat defaultBureaucrat;
    std::cout << "Created bureaucrat: " << defaultBureaucrat << std::endl;
	} catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
	}
}

static void testGradeManipulation() {
	testHelperPrintSection("Grade Manipulation");

	try {
		Bureaucrat daniel("Daniel Trigo", 42);
    std::cout << "Initial state: " << daniel << std::endl;

    daniel.incrementGrade();
    std::cout << "After increment: " << daniel << std::endl;

    daniel.decrementGrade();
    std::cout << "After decrement: " << daniel << std::endl;

    daniel.decrementGrade();
    std::cout << "After decrement: " << daniel << std::endl;
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
	}
}

static void testInvalidConstruction() {
  testHelperPrintSection("Invalid Construction");

  try {
    testHelperLog(RESET, "Attempting to create bureaucrat with grade 0...");
    Bureaucrat invalidHigh("Too High", 0);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooHighException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }

  std::cout << std::endl;

  try {
    testHelperLog(RESET, "Attempting to create bureaucrat with grade 151...");
    Bureaucrat invalidLow("Too Low", 151);
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooLowException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}

static void testBoundaryConditions() {
  testHelperPrintSection("Boundary Conditions");

  try {
    Bureaucrat topBureaucrat("The Boss", 1);
    std::cout << "Created bureaucrat: " << topBureaucrat << std::endl;
    testHelperLog(RESET, "Attempting to incrementgrade 1...");
    topBureaucrat.incrementGrade();
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooHighException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }

  std::cout << std::endl;

  try {
    Bureaucrat bottomBureaucrat("Intern", 150);
    std::cout << "Created bureaucrat: " << bottomBureaucrat << std::endl;
    testHelperLog(RESET, "Attempting to decrement 150...");
    bottomBureaucrat.decrementGrade();
    testHelperLog(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    testHelperLog(ORANGE, "Correctly caught GradeTooLowException:");
    testHelperLog(RED, e.what());
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
  }
}

static void testCopyOperations() {
  testHelperPrintSection("Copy Operations");

  try {
    Bureaucrat original("Original", 42);
    std::cout << "Original: " << original << std::endl;

    std::cout << std::endl;
    Bureaucrat copy(original);
    std::cout << "Copy constructed: " << copy << std::endl;

    std::cout << std::endl;
    Bureaucrat assigned("Temporary", 111);
    std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;

    std::cout << std::endl;
    original.incrementGrade();
		std::cout << "After modifying original:" << std::endl;
		std::cout << "  Original: " << original << std::endl;
		std::cout << "  Copy: " << copy << std::endl;
		std::cout << "  Assigned: " << assigned << std::endl;
  } catch (const std::exception& e) {
    testHelperLog(ORANGE, "Expection caught:");
    testHelperLog(RED, e.what());
  }
}
