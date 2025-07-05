/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelpers.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:30:07 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/05 10:00:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/TestHelpers.hpp"
#include "utils/TerminalColor.hpp"
#include <iostream>

void testHelperLog(StrColor strColor, const std::string str) {
  const TerminalColor& color = TerminalColor::getInstance();
  std::cout << color.setColor(strColor, str) << std::endl;
}

void testHelperPrintSection(StrColor titleColor, const std::string& title) {
  testHelperLog(titleColor, "\n" + std::string(TEST_LINE_SIZE, '='));
	testHelperLog(titleColor, "TEST: " + title);
  testHelperLog(titleColor, std::string(TEST_LINE_SIZE, '='));
}
