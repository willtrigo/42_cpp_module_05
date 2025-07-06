/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:40:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/06 14:41:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_COLOR_HPP
#define TERMINAL_COLOR_HPP

#include <string>
#include <utility>

enum StrColor {
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  PURPLE,
  CYAN,
  WHITE,
  ORANGE,
  RESET
};

enum BgColor {
  BG_BLACK,
  BG_RED,
  BG_GREEN,
  BG_YELLOW,
  BG_BLUE,
  BG_PURPLE,
  BG_CYAN,
  BG_WHITE,
  BG_ORANGE,
  BG_RESET
};

enum Style {
  BOLD,
  ITALIC,
  UNDERLINE
};

class TerminalColor {
 public:
  ~TerminalColor();

  static TerminalColor& getInstance();

  std::string setColor(StrColor strColor, const std::string& str) const;
  std::string setColor(BgColor bgColor, const std::string& str) const;
  std::string setColor(Style style, const std::string& str) const;
  std::string setColor(BgColor bgColor, StrColor strColor, const std::string& str) const;
  std::string setColor(BgColor bgColor, Style style, const std::string& str) const;
  std::string setColor(StrColor strColor, Style style, const std::string& str) const;
  std::string setColor(BgColor bgColor, StrColor strColor, Style style, const std::string& str) const;

 private:
  TerminalColor();
  TerminalColor(const TerminalColor&);
  TerminalColor& operator=(const TerminalColor&);

  static const std::pair<StrColor, std::string> STR_COLOR_MAP[];
  static const std::pair<BgColor, std::string> BG_COLOR_MAP[];
  static const std::pair<Style, std::string> STYLE_MAP[];
};

#endif // TERMINAL_COLOR_HPP
