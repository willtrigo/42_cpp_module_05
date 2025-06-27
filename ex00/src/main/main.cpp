/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:07:39 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/27 00:06:05 by dande-je         ###   ########.fr       */
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

int main() {
  log(GREEN, "=== BUREAUCRAT TESTING SUITE ===");

	testBasicFunctionality();
  testGradeManipulation();
  testInvalidConstruction();

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
    Bureaucrat invalidHigh("Too Low", 151);
    log(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    log(ORANGE, "Correctly caught GradeTooLowException:");
    log(RED, e.what());
  } catch (const std::exception& e) {
    log(ORANGE, "Caught unexpected exception:");
    log(RED, e.what());
  }
}
