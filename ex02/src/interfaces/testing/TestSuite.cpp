/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestSuite.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:47:40 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/07 19:17:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestHelpers.hpp"
#include "utils/logging/TerminalColor.hpp"

void runTests() {
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
  testHelperLog(GREEN, "BUREAUCRAT TESTING SUITE");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
  testHelperLog(GREEN, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(GREEN, "ALL TESTS COMPLETED");
  testHelperLog(GREEN, std::string(TEST_LINE_SIZE, '='));
}
