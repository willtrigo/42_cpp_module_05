/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestSuite.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:45 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/06 13:20:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/TestEx00.hpp"
#include "test/TestEx01.hpp"
#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"

void runTests() {
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
  testHelperLog(GREEN, "BUREAUCRAT TESTING SUITE");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
  runAllEx00Tests();
  runAllEx01Tests();
  testHelperLog(GREEN, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(GREEN, "ALL TESTS COMPLETED");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
}
