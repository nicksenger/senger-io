module WT = Wonka.Types;

let combineEpics: list(WT.sourceT('a)) => WT.sourceT('a) =
  actionStreams => {
    let {WT.source, WT.next} = Wonka.makeSubject();
    List.iter(
      s =>
        s((. a) =>
          switch (a) {
          | WT.Push(a) => next(a)
          | _ => ()
          }
        ),
      actionStreams,
    );
    source;
  };

let submitMessageEpic = (actionStream, _stateStream) =>
  actionStream
  |> Wonka.filter((. a) =>
       switch (a) {
       | Types.SubmitMessageRequest(_, _) => true
       | _ => false
       }
     )
  |> Wonka.mergeMap((. a) =>
       switch (a) {
       | Types.SubmitMessageRequest(email, message) =>
         let payload = Js.Dict.empty();
         Js.Dict.set(payload, "email", Js.Json.string(email));
         Js.Dict.set(payload, "message", Js.Json.string(message));
         Wonka.fromPromise(
           Fetch.fetchWithInit(
             "/send-message",
             Fetch.RequestInit.make(
               ~method_=Post,
               ~body=
                 Fetch.BodyInit.make(
                   Js.Json.stringify(Js.Json.object_(payload)),
                 ),
               ~headers=
                 Fetch.HeadersInit.make({"Content-Type": "application/json"}),
               (),
             ),
           ),
         )
         |> Wonka.map((. r) =>
              switch (Fetch.Response.status(r)) {
              | 200 => Types.SubmitMessageSuccess
              | _ => Types.SubmitMessageFailure
              }
            );
       | _ => Wonka.fromList([])
       }
     );

let submitMessageCompletionEpic = (actionStream, _stateStream, push) =>
  actionStream
  |> Wonka.filter((. a) =>
       switch (a) {
       | Types.SubmitMessageSuccess =>
         push("/contact?success=true");
         false;
       | Types.SubmitMessageFailure =>
         push("/contact?success=false");
         false;
       | _ => false
       }
     );

let rootEpic = (actionStream, stateStream) =>
  combineEpics([
    submitMessageEpic(actionStream, stateStream),
    submitMessageCompletionEpic(
      actionStream,
      stateStream,
      ReasonReactRouter.push,
    ),
  ]);