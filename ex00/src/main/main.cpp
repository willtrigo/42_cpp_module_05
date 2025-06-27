/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:07:39 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/27 00:42:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Bureaucrat.hpp"
#include "utils/TerminalColor.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>

const int LINE_SIZE = 80;
static void log(StrColor strColor, const std::string str);
static void testBasicFunctionality();
static void testGradeManipulation();
static void testInvalidConstruction();
static void testBoundaryConditions();
static void testCopyOperations();

int main() {
  log(GREEN, "=== BUREAUCRAT TESTING SUITE ===");

	testBasicFunctionality();
  testGradeManipulation();
  testInvalidConstruction();
  testBoundaryConditions();
  testCopyOperations();

  log(GREEN, "\n" + std::string(LINE_SIZE, '='));
	log(GREEN, "ALL TESTS COMPLETED");
  log(GREEN, std::string(LINE_SIZE, '='));
  return EXIT_SUCCESS;
}

static void log(StrColor strColor, const std::string str) {
  const TerminalColor& color = TerminalColor::getInstance();
  std::cout << color.setColor(strColor, str) << std::endl;
}

static void printTestSection(const std::string& title) {
  log(BLUE, "\n" + std::string(LINE_SIZE, '='));
	log(YELLOW, "TEST: " + title);
  log(BLUE, std::string(LINE_SIZE, '='));
}

static void testBasicFunctionality() {
	printTestSection("Basic Functionality");

	try {
		Bureaucrat daniel("Daniel Trigo", 42);
    std::cout << "Created bureaucrat: " << daniel << std::endl;
    std::cout << "Name: " << daniel.getName() << std::endl;
		std::cout << "Grade: " << daniel.getGrade() << std::endl;

    std::cout << std::endl;

		Bureaucrat defaultBureaucrat;
    std::cout << "Created bureaucrat: " << defaultBureaucrat << std::endl;
	} catch (const std::exception& e) {
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
	}
}

static void testGradeManipulation() {
	printTestSection("Grade Manipulation");

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
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
	}
}

static void testInvalidConstruction() {
  printTestSection("Invalid Construction");

  try {
    log(RESET, "Attempting to create bureaucrat with grade 0...");
    Bureaucrat invalidHigh("Too High", 0);
    log(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    log(ORANGE, "Correctly caught GradeTooHighException:");
    log(RED, e.what());
  } catch (const std::exception& e) {
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
  }

  std::cout << std::endl;

  try {
    log(RESET, "Attempting to create bureaucrat with grade 151...");
    Bureaucrat invalidLow("Too Low", 151);
    log(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    log(ORANGE, "Correctly caught GradeTooLowException:");
    log(RED, e.what());
  } catch (const std::exception& e) {
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
  }
}

static void testBoundaryConditions() {
  printTestSection("Boundary Conditions");

  try {
    Bureaucrat topBureaucrat("The Boss", 1);
    std::cout << "Created bureaucrat: " << topBureaucrat << std::endl;
    log(RESET, "Attempting to incrementgrade 1...");
    topBureaucrat.incrementGrade();
    log(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    log(ORANGE, "Correctly caught GradeTooHighException:");
    log(RED, e.what());
  } catch (const std::exception& e) {
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
  }

  std::cout << std::endl;

  try {
    Bureaucrat bottomBureaucrat("Intern", 150);
    std::cout << "Created bureaucrat: " << bottomBureaucrat << std::endl;
    log(RESET, "Attempting to decrement 150...");
    bottomBureaucrat.decrementGrade();
    log(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    log(ORANGE, "Correctly caught GradeTooLowException:");
    log(RED, e.what());
  } catch (const std::exception& e) {
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
  }
}

static void testCopyOperations() {
  printTestSection("Copy Operations");

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
    log(ORANGE, "Expection caught:");
    log(RED, e.what());
  }
}
