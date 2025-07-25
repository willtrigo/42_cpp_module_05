/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureaucratTests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:20:41 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/24 23:08:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/domain/BureaucratTests.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestRunner.hpp"
#include <iostream>
#include <stdexcept>

BureaucratTests::BureaucratTests() {}

BureaucratTests::BureaucratTests(const BureaucratTests&) {}

BureaucratTests::~BureaucratTests() {}

BureaucratTests& BureaucratTests::operator=(const BureaucratTests&) {
  throw std::runtime_error("Copying of BureaucratTests is not allowed");
}

void BureaucratTests::createTestSuite() {
  BureaucratTests::testBasicFuntionality();
  BureaucratTests::testGradeManipulation();
  BureaucratTests::testInvalidConstruction();
  BureaucratTests::testBoundaryConditions();
  BureaucratTests::testCopyOperations();
}

void BureaucratTests::testBasicFuntionality() {
  TestRunner::PrintSection(YELLOW, YELLOW, true, "Bureaucrat Basic Functionality");

  try {
    Bureaucrat daniel("Daniel Trigo", 42);
    BureaucratPrinter::print(std::cout, daniel);

    StreamWriter::print(RESET, "");

    Bureaucrat defaultBureaucrat;
    BureaucratPrinter::print(std::cout, defaultBureaucrat);
	} catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
	}
}

void BureaucratTests::testGradeManipulation() {
  TestRunner::PrintSection(YELLOW, YELLOW, true, "Bureaucrat Grade Manipulation");

  try {
    Bureaucrat daniel("Daniel Trigo", 42);
    StreamWriter::print(GREEN, "Initial state:");
    BureaucratPrinter::print(std::cout, daniel);

    daniel.incrementGrade();
    StreamWriter::print(BLUE, "After increment:");
    BureaucratPrinter::print(std::cout, daniel);

    daniel.decrementGrade();
    StreamWriter::print(YELLOW, "After decrement:");
    BureaucratPrinter::print(std::cout, daniel);

    daniel.decrementGrade();
    StreamWriter::print(YELLOW, "After decrement:");
    BureaucratPrinter::print(std::cout, daniel);
	} catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
	}
}

void BureaucratTests::testInvalidConstruction() {
  TestRunner::PrintSection(YELLOW, YELLOW, true, "Bureaucrat Invalid Construction");

  try {
    StreamWriter::print(RESET, "Attempting to create bureaucrat with grade 0...");
    Bureaucrat invalidHigh("Too High", 0);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  StreamWriter::print(RESET, "");

  try {
    StreamWriter::print(RESET, "Attempting to create bureaucrat with gradea 151...");
    Bureaucrat invalidLow("Too Low", 151);
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void BureaucratTests::testBoundaryConditions() {
  TestRunner::PrintSection(YELLOW, YELLOW, true, "Bureaucrat Boundary Conditions");

  try {
    Bureaucrat topBureaucrat("The Boss", 1);
    StreamWriter::print(GREEN, "Created bureaucrat:");
    BureaucratPrinter::print(std::cout, topBureaucrat);
    StreamWriter::print(BLUE, "Attempting to incrementgrade 1...");
    topBureaucrat.incrementGrade();
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooHighException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooHighException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }

  StreamWriter::print(RESET, "");

  try {
    Bureaucrat bottomBureaucrat("Intern", 150);
    StreamWriter::print(GREEN, "Created bureaucrat:");
    BureaucratPrinter::print(std::cout, bottomBureaucrat);
    StreamWriter::print(YELLOW, "Attempting to decrement 150...");
    bottomBureaucrat.decrementGrade();
    StreamWriter::print(RED, "Error: should have throw exception");
  } catch (const Bureaucrat::GradeTooLowException& e) {
    StreamWriter::print(ORANGE, "Correctly caught GradeTooLowException:");
    StreamWriter::print(RED, e.what());
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Caught unexpected exception:");
    StreamWriter::print(RED, e.what());
  }
}

void BureaucratTests::testCopyOperations() {
  TestRunner::PrintSection(YELLOW, YELLOW, true, "Bureaucrat Copy Operations");

  try {
    Bureaucrat original("Original", 42);
    StreamWriter::print(GREEN, "Original bureaucrat:");
    BureaucratPrinter::print(std::cout, original);

    StreamWriter::print(RESET, "");

    Bureaucrat copy(original);
    StreamWriter::print(ORANGE, "Copy bureaucrat:");
    BureaucratPrinter::print(std::cout, copy);

    StreamWriter::print(RESET, "");

    Bureaucrat assigned("Temporary", 111);
    StreamWriter::print(PURPLE, "Before assignment bureaucrat:");
    BureaucratPrinter::print(std::cout, assigned);
		assigned = original;
    StreamWriter::print(PURPLE, "After assignment bureaucrat:");
    BureaucratPrinter::print(std::cout, assigned);

    StreamWriter::print(RESET, "");

    StreamWriter::print(CYAN, "After modifying Original bureaucrat:");
    original.incrementGrade();
    StreamWriter::print(GREEN, "Original bureaucrat:");
    BureaucratPrinter::print(std::cout, original);
    StreamWriter::print(ORANGE, "Copy bureaucrat:");
    BureaucratPrinter::print(std::cout, copy);
    StreamWriter::print(PURPLE, "Assignment bureaucrat:");
    BureaucratPrinter::print(std::cout, assigned);
  } catch (const std::exception& e) {
    StreamWriter::print(ORANGE, "Expection caught:");
    StreamWriter::print(RED, e.what());
  }
}
