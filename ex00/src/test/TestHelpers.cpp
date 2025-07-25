/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelpers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:27:44 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/29 14:35:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

void testHelperLog(StrColor strColor, const std::string str) {
  const TerminalColor& color = TerminalColor::getInstance();
  std::cout << color.setColor(strColor, str) << std::endl;
}

void testHelperPrintSection(const std::string& title) {
  testHelperLog(BLUE, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(YELLOW, "TEST: " + title);
  testHelperLog(BLUE, std::string(TEST_LINE_SIZE, '='));
}
