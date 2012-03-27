/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *
 *  Copyright:
 *
 *  Last modified:
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

namespace Gecode { namespace Float {

  /*
   * Constructors and initialization
   *
   */
  forceinline
  ScaleView::ScaleView(void) {}
  forceinline
  ScaleView::ScaleView(FloatVal d, const FloatView& y)
    : DerivedView<FloatView>(y), a(d) {}


  /*
   * Value access
   *
   */
  forceinline FloatVal
  ScaleView::scale(void) const {
    return a;
  }
  forceinline FloatInterval
  ScaleView::domain(void) const {
    return x.domain()*a;
  }
  forceinline FloatNum
  ScaleView::min(void) const {
    FloatVal c = x.min(); c *= a; return c.lower();
  }
  forceinline FloatNum
  ScaleView::max(void) const {
    FloatVal c = x.max(); c *= a; return c.upper();
  }
  forceinline FloatVal
  ScaleView::med(void) const {
    FloatVal c = x.med(); c *= a; return c;
  }
  forceinline FloatNum
  ScaleView::median(void) const {
    FloatVal c = x.median(); c *= a; return (c.lower()+c.upper())/2;
  }
  forceinline FloatVal
  ScaleView::val(void) const {
    FloatVal c = x.val(); c *= a; return c;
  }

  forceinline FloatNum
  ScaleView::width(void) const {
    FloatVal c = x.width(); c *= a; return c.upper();
  }


  /*
   * Domain tests
   *
   */
  forceinline bool
  ScaleView::zero_in() const {
    return x.zero_in();
  }
  forceinline bool
  ScaleView::in(FloatNum n) const {
    return x.in(n/a);
  }
  forceinline bool
  ScaleView::in(const FloatInterval& n) const {
    return x.in(n/a);
  }


  /*
   * Domain update by value
   *
   */
  forceinline ModEvent
  ScaleView::lq(Space& home, int n) {
    FloatVal c = n; c /= a;
    return x.lq(home,c.upper());
  }
  forceinline ModEvent
  ScaleView::lq(Space& home, FloatNum n) {
    FloatVal c = n; c /= a;
    return x.lq(home,c.upper());
  }
  forceinline ModEvent
  ScaleView::lq(Space& home, FloatVal n) {
    FloatVal c = n; c /= a;
    return x.lq(home,c.upper());
  }

  forceinline ModEvent
  ScaleView::gq(Space& home, int n) {
    FloatVal c = n; c /= a;
    return x.gq(home,c.lower());
  }
  forceinline ModEvent
  ScaleView::gq(Space& home, FloatNum n) {
    FloatVal c = n; c /= a;
    return x.gq(home,c.lower());
  }
  forceinline ModEvent
  ScaleView::gq(Space& home, FloatVal n) {
    FloatVal c = n; c /= a;
    return x.gq(home,c.lower());
  }

  forceinline ModEvent
  ScaleView::eq(Space& home, int n) {
    FloatVal c = n; c /= a;
    return x.eq(home,c);
  }
  forceinline ModEvent
  ScaleView::eq(Space& home, FloatNum n) {
    FloatVal c = n; c /= a;
    return x.eq(home,c);
  }
  forceinline ModEvent
  ScaleView::eq(Space& home, const FloatVal& n) {
    FloatVal c = n; c /= a;
    return x.eq(home,c);
  }

  forceinline ModEvent
  ScaleView::nq(Space& home, int n) {
    FloatVal c = n; c /= a;
    return x.nq(home,c);
  }
  forceinline ModEvent
  ScaleView::nq(Space& home, FloatNum n) {
    FloatVal c = n; c /= a;
    return x.nq(home,c);
  }
  forceinline ModEvent
  ScaleView::nq(Space& home, const FloatVal& n) {
    FloatVal c = n; c /= a;
    return x.nq(home,c);
  }


  /*
   * Delta information for advisors
   *
   */
  forceinline FloatNum
  ScaleView::min(const Delta& d) const {
    FloatVal c = x.min(d); c *= a; return c.lower();
  }
  forceinline FloatNum
  ScaleView::max(const Delta& d) const {
    FloatVal c = x.max(d); c *= a; return c.upper();
  }

  forceinline ModEventDelta
  ScaleView::med(ModEvent me) {
    return VarImpView<FloatVar>::med(me);
  }


  /*
   * Cloning
   *
   */
  forceinline void
  ScaleView::update(Space& home, bool share, ScaleView& y) {
    DerivedView<FloatView>::update(home,share,y);
    a=y.a;
  }

}}

// STATISTICS: float-var
