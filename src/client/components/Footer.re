[@react.component]
let make = (~route: Types.route, ~menuOpen) =>
  <footer
    className=(
      switch (menuOpen) {
      | Types.Open => "sio__footer sio__footer--shifted"
      | _ => "sio__footer"
      }
    )>
    <A
      className=(
        switch (route) {
        | Types.Home => "sio__footer-link sio__footer-link--active"
        | _ => "sio__footer-link"
        }
      )
      href="/home">
      <svg
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 12.418 11.002"
        height="41.584"
        width="46.934">
        <g fill="currentColor">
          <path
            d="M1.688 10.725s-.01.277.26.277l3.13-.004.006-2.564s-.044-.423.366-.423h1.299c.485 0 .455.423.455.423l-.005 2.557h3.063c.345 0 .329-.346.329-.346V5.917L6.273 2.075 1.688 5.917v4.808"
          />
          <path
            d="M0 5.56s.39.717 1.238 0L6.31 1.267l4.757 4.264c.983.709 1.35 0 1.35 0L6.31 0 0 5.56M10.951 1.257H9.728l.006 1.484 1.217 1.033V1.257"
          />
        </g>
      </svg>
      (React.string("HOME"))
    </A>
    <A
      className=(
        switch (route) {
        | Types.About => "sio__footer-link sio__footer-link--active"
        | _ => "sio__footer-link"
        }
      )
      href="/about">
      <svg viewBox="0 0 12.418 12.219" height="46.181" width="46.933">
        <g fill="currentColor">
          <path
            d="M3.032 0H.474A.475.475 0 0 0 0 .475v2.557c0 .262.212.475.474.475h2.558a.474.474 0 0 0 .473-.475V.475A.475.475 0 0 0 3.032 0M7.437 0H4.88a.475.475 0 0 0-.474.475v2.557c0 .262.213.475.474.475h2.557a.474.474 0 0 0 .474-.475V.475A.475.475 0 0 0 7.437 0M11.944 0H9.387a.475.475 0 0 0-.474.475v2.557c0 .262.212.475.474.475h2.557a.475.475 0 0 0 .474-.475V.475A.475.475 0 0 0 11.944 0M3.032 4.307H.474A.474.474 0 0 0 0 4.781v2.557c0 .262.212.474.474.474h2.558a.474.474 0 0 0 .473-.474V4.781a.474.474 0 0 0-.473-.474M7.437 4.307H4.88a.474.474 0 0 0-.474.474v2.557c0 .262.213.474.474.474h2.557a.474.474 0 0 0 .474-.474V4.781a.474.474 0 0 0-.474-.474M11.944 4.307H9.387a.474.474 0 0 0-.474.474v2.557c0 .262.212.474.474.474h2.557a.474.474 0 0 0 .474-.474V4.781a.474.474 0 0 0-.474-.474M3.032 8.713H.474A.474.474 0 0 0 0 9.187v2.557c0 .262.212.475.474.475h2.558a.474.474 0 0 0 .473-.475V9.187a.474.474 0 0 0-.473-.474M7.437 8.713H4.88a.474.474 0 0 0-.474.474v2.557c0 .262.213.475.474.475h2.557a.474.474 0 0 0 .474-.475V9.187a.474.474 0 0 0-.474-.474M11.944 8.713H9.387a.474.474 0 0 0-.474.474v2.557c0 .262.212.475.474.475h2.557a.475.475 0 0 0 .474-.475V9.187a.474.474 0 0 0-.474-.474"
          />
        </g>
      </svg>
      (React.string("ABOUT"))
    </A>
    <A
      className=(
        switch (route) {
        | Types.Contact => "sio__footer-link sio__footer-link--active"
        | _ => "sio__footer-link"
        }
      )
      href="/contact">
      <svg
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 15.819 16.958"
        height="64.092"
        width="59.787">
        <g fill="currentColor">
          <path
            d="M10.298 0L2.056 9.133l1.222 1.104 8.242-9.132L10.298 0M14.596 3.88l-8.242 9.132 1.222 1.103 8.243-9.132-1.223-1.104M11.825 1.379L3.582 10.51l2.467 2.226 8.243-9.131-2.467-2.227M.52 14.734L0 16.958l2.159-.744a2.273 2.273 0 0 0-1.639-1.48M.687 14.268A2.659 2.659 0 0 1 2.606 16l4.565-1.571-5.388-4.856-1.096 4.695"
          />
        </g>
      </svg>
      (React.string("CONTACT"))
    </A>
  </footer>;