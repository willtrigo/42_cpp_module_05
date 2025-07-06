/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestSuite.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:00:00 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/06 13:23:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/TestEx00.hpp"
#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"

void runTests() {
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
  testHelperLog(GREEN, "BUREAUCRAT TESTING SUITE");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
  runAllEx00Tests();
  testHelperLog(GREEN, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(GREEN, "ALL TESTS COMPLETED");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
}
