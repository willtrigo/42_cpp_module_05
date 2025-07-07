/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColorUtility.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:40:47 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/07 19:18:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/logging/TerminalColor.hpp"

std::string TerminalColor::setColor(StrColor strColor, const std::string& str) const {
  std::string result;

  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(BgColor bgColor, const std::string& str) const {
  std::string result;

  result += BG_COLOR_MAP[bgColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(Style style, const std::string& str) const {
  std::string result;

  result += STYLE_MAP[style].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(BgColor bgColor, StrColor strColor, const std::string& str) const {
  std::string result;

  result += BG_COLOR_MAP[bgColor].second;
  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(StrColor strColor, Style style, const std::string& str) const {
  std::string result;

  result += STYLE_MAP[style].second;
  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(BgColor bgColor, StrColor strColor, Style style, const std::string& str) const {
  std::string result;

  result += STYLE_MAP[style].second;
  result += BG_COLOR_MAP[bgColor].second;
  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}
