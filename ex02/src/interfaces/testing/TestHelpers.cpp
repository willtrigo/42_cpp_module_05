/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelpers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:48:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 15:44:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interfaces/testing/TestHelpers.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <iostream>

void testHelperLog(StrColor strColor, const std::string str) {
  std::cout << TerminalColor::setColor(strColor, str) << std::endl;
}

void testHelperPrintSection(StrColor titleColor, const std::string& title) {
  testHelperLog(titleColor, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(titleColor, "TEST: " + title);
  testHelperLog(titleColor, std::string(TEST_LINE_SIZE, '='));
}
