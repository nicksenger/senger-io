[@react.component]
let make = (~menuOpen, ~toggleMenu) => {
  <div
    onWheel={(e) => ReactEvent.Wheel.preventDefault(e)}
    className=(menuOpen ? "sio__burger-container" : "sio__burger-container sio__burger-container--closed")
  >
    <div
        className=(menuOpen ? "sio__burger-panel" : "sio__burger-panel sio__burger-panel--closed")
    >
        <A href="/home" onClick=(Some(_ => toggleMenu()))>(React.string("HOME"))</A>
        <A href="/about" onClick=(Some(_ => toggleMenu()))>(React.string("ABOUT"))</A>
        <A href="/contact" onClick=(Some(_ => toggleMenu()))>(React.string("CONTACT"))</A>
    </div>
  </div>
}