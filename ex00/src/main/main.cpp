/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:07:39 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/25 17:28:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/Bureaucrat.hpp"
#include "utils/TerminalColor.hpp"
#include <cstdlib>
#include <iostream>

const int LINE_SIZE = 80;
static void log(StrColor strColor, const std::string str);
static void testBasicFunctionality();

int main() {
  log(GREEN, "=== BUREAUCRAT TESTING SUITE ===");

	testBasicFunctionality();

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

	try
	{
		Bureaucrat daniel("Daniel Trigo", 42);
    std::cout << "Created bureaucrat: " << daniel << std::endl;
    std::cout << "Name: " << daniel.getName() << std::endl;
		std::cout << "Grade: " << daniel.getGrade() << std::endl;

    std::cout << std::endl;

		Bureaucrat defaultBureaucrat;
    std::cout << "Created bureaucrat: " << defaultBureaucrat << std::endl;
	}
	catch (const std::exception& e)
	{
    log(RED, e.what());
	}
}
