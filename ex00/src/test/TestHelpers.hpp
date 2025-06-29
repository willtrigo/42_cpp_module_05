/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestHelpers.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:27:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/29 14:35:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTSUITE_HPP
#define TESTSUITE_HPP

#include "utils/TerminalColor.hpp"

static const int TEST_LINE_SIZE = 80;

void testHelperLog(StrColor strColor, const std::string str);
void testHelperPrintSection(const std::string& title);

#endif // TESTSUITE_HPP
