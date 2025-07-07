/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelpers.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:48:18 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/07 19:18:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#include "utils/logging/TerminalColor.hpp"

static const int TEST_LINE_SIZE = 80;

void testHelperLog(StrColor strColor, const std::string str);
void testHelperPrintSection(StrColor titleColor, const std::string& title);

#endif // TESTSUITE_HPP
