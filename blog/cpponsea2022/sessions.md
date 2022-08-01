# C++ On Sea 2022 - Trip Report
Folkestone, UK, July 4-7  

This year, I was delighted to return (on-site) to the **C++ On Sea** conference. This post is a summary of the sessions I attended and enjoyed.  
Check out this [separate post](./tripreport.html) for my general impressions of the conference (trip report summary).  

## Plenary Sessions

This year we had 4 plenary sessions. Here's a quick highlight:  

### Hana Dusíková - [Lightning Updates](https://cpponsea.uk/2022/sessions/keynote-lightning-updates.html)  
Hana presented a nifty custom differential update system (think "Git") as a showcase for cool C++20 features usage. Her skills of progressively walking us through the code and meticulously highlighting the important bits are _legendary_ - enough said.  
![](img/sessions/hana_1.jpeg)  
![](img/sessions/hana_2.jpeg)  
![](img/sessions/hana_3.jpeg)  

### Kevlin Henney - [For the Sake of Complexity](https://cpponsea.uk/2022/sessions/midnote-for-the-sake-of-complexity.html)  
For me, Kevlin's keynotes are the highlight of any conference. As usual, he didn't disappoint.😄  
A fantastic overview of the complexity in software systems: from our code, from the nature of software development to the detail of coding habits, from design practices through to the core language.  
![](img/sessions/kevlin_1.jpeg)  
![](img/sessions/kevlin_2.jpeg)  
![](img/sessions/kevlin_3.jpeg)  

### Jason Turner - [Making C++ Fun, Safe, and Accessible](https://cpponsea.uk/2022/sessions/endnote-making-cpp-fun-safe-and-accessible.html)  
C++ has a reputation for being hard to learn with annoying errors and dangerous memory issues. Jason explores various ways in which we make C++ fun and safe and accessible to a larger audience. This is a topic worth investing in for the new generation of programmers, as C++ isn't going anywhere soon and teaching it properly really matters. First steps make a difference...     
![](img/sessions/jason_1.jpeg)  
![](img/sessions/jason_2.jpeg)  

### Victor Ciura - [C++ MythBusters](https://cpponsea.uk/2022/sessions/plenary-cpp-mythbusters.html)  
... and my own session 😄  
I dissected a few of the most popular C++ myths to a level of detail not possible on Twitter… and without the stigma of newb/duplicate/eyeroll one might experience when asking these questions on StackOverflow. The familiar “Busted”, “Plausible”, or “Confirmed” verdicts on each myth. 
I probably started some controversy and hopefully constructive discussions around a few sensitive topics in contemporary C++.  
![](img/sessions/victor_1.png)  

## Sessions I liked

Out of the 3-day x 4 tracks [schedule](https://cpponsea.uk/2022/schedule/), full of interesting talks, I managed to attended 15 sessions that I found very engaging. Here they are, in chronological order.   

### Walter E Brown - [A Medley of C++](https://cpponsea.uk/2022/sessions/a-medley-of-cpp.html)  
It is a real privilege to listen to Walter's stories, both on stage and especially on the hallway, during breaks. An industry veteran with tons of experience using various systems, languages, techniques and a wonderful human being eager to share his experience with younger generations. This set of short presentations were both captivating and informative. A must see!    
![](img/sessions/walter_1.jpeg)  


### Bryce Adelstein Lelbach - [C++ Standard Parallelism](https://cpponsea.uk/2022/sessions/cpp-standard-parallelism.html)  
C++20 opened the door for programmers to leverage the full power of our silicon. Imagine writing parallel code that can run on _any_ platform - CPUs, GPUs, DPUs, accelerators - without any language or vendor extensions, external libraries or special compilers. Just standard C++.   
Starter examples of using schedulers, senders, receivers and ways to handle notifications and state changes. These new tools will completely reshape the way our parallel code will look like.  
A bonus section in this talk was about the shinny new `std::mdspan` (C++23), that will allow us flexible addressing of different shapes of data.    
![](img/sessions/bryce_1.jpeg)  
![](img/sessions/bryce_2.jpeg)  
![](img/sessions/bryce_3.jpeg)  


### Dawid Zalewski - [To pass and return — the story of functions, values and compilers](https://cpponsea.uk/2022/sessions/to-pass-and-return-the-story-of-functions-values-and-compilers.html)  
The story of passing arguments to functions might be diverse depending on architectures, ABI and calling conventions, but at least it's clear. Returning from functions on the other hand is a different story. Dawid explores the intricate details of copy elision, RVO, NRVO on different compilers - the way it looks today, as the story keeps changing with newer versions...    
![](img/sessions/david_0.jpeg)  
![](img/sessions/david_1.jpeg)  
![](img/sessions/david_2.jpeg)  


### Ólafur Waage - [Sandbox Games: Using WebAssembly and C++ to make a simple game](https://cpponsea.uk/2022/sessions/sandbox-games-using-webassembly-and-cpp-to-make-a-simple-game.html)  
Every conference has a session that is fun/entertaining, but you learn something new in the process. This was it, at C++ On Sea. Ólafur showed us how he learned about WebAssembly by making a game. A nice intro to the frameworks, the toolchain and the debugging experience. A refreshing way to C++. There’s no escaping CMake… not even with WASM - `CMAKE_EXECUTABLE_SUFFIX .html` 😄   
![](img/sessions/olaf_1.jpeg)  
![](img/sessions/olaf_2.jpeg)  
![](img/sessions/olaf_3.jpeg)  


### Daniela Engert - [Contemporary C++ in Action](https://cpponsea.uk/2022/sessions/contemporary-cpp-in-action.html)  
An application showcase/demo where Daniela is, of course 😄, using C++20 modules, does some network programming with coroutines (based on ASIO executors), with the occasional C++23 features...  
Daniela pushes the limits of currently available stuff in new compiler versions - at the moment, only **MSVC** supports all the features needed by her implementation; and that's on _Preview versions_ of VS2022! Daniela submitted so many bugs and feedback to our Visual C++ team, that she practically accelerated our C++20/23 conformance 👍  
If you want to see this fleshed out even further, watch Daniela's keynotes at CppCon and Meeting C++, in a few months. She told me she has more cool things coming.  
![](img/sessions/dani_1.jpeg)  
![](img/sessions/dani_2.jpeg)  
![](img/sessions/dani_3.jpeg)  


### David Winterbottom - [Help, My Team Is Stuck In The 90s](https://cpponsea.uk/2022/sessions/help-my-team-is-stuck-in-the-90s.html)  
With a title like this, I couldn't resist attending this talk. And yeah, David comes from the gaming industry :)   
The presentation had lots of good advice for teams wanting to move forward and I found most of it just common sense. But it needs to be said and said again, until most folks hear it. What I liked most about this session was the long Q&A portion at the end where people asked on point questions and shared opinions & ideas from their experience/teams. David was so nice and honest about their experience; I hope I'll see them at another conference soon.   
![](img/sessions/winter_1.jpeg)  
![](img/sessions/winter_2.jpeg)  
![](img/sessions/winter_3.jpeg)  


### Anthony Williams - [An introduction to multithreading in C++20](https://cpponsea.uk/2022/sessions/an-introduction-to-multithreading-in-cpp20.html)  
This presentation was exactly what it said in the title/abstract. And Anthony is _The_ person with the right knowledge & experience to frame this kind of overview presentation of the multithreading facilities in contemporary C++. What I liked most about this talk was that Anthony presented the multithreading library facilities in the _order_ most programmers need to reach for them. This is particular good advice as it's very easy to get yourself into trouble by using the wrong synchronization abstraction for your problem. Not having the right tools is bad, but having too many and not knowing when to use the appropriate one is just as perilous.    
![](img/sessions/williams_1.jpeg)  
![](img/sessions/williams_2.jpeg)  
![](img/sessions/williams_3.jpeg)  


### Arne Mertz - [Identifying common code smells](https://cpponsea.uk/2022/sessions/identifying-common-code-smells.html)  
I'll be honest, I heard great reviews about this presentation from past conferences but I didn't get around to watch a recording. So I was determined to see it live, now. Arne didn't disappoint, the recommendations were right. A plethora of examples hand-picked from open source code where Arne pointed out various kinds of code smells and simple ways to improve them.   
![](img/sessions/arne_1.jpeg)  
![](img/sessions/arne_2.jpeg)  
![](img/sessions/arne_3.jpeg)  


### Peter Bindels - [What's in a bit - Designing, using and reverse-engineering binary file formats](https://cpponsea.uk/2022/sessions/whats-in-a-bit-designing-using-and-reverse-engineering-binary-file-formats.html)  
What can bits really represent? Peter starts with a crash course on the basics of binary representations and encodings and then he explores designs for a binary file format. This part was informative; the next part was on reverse engineering binary files. Talk about a rabbit hole - this was fun! Like a puzzle, you have no idea where that `00101101` piece goes... could be a fun hobby to take on. Peter sure seems to enjoy it 😄  
![](img/sessions/bindels_1.jpeg)  
![](img/sessions/bindels_2.jpeg)  


### Jonathan Müller - [Coroutines: C++ vs Rust](https://cpponsea.uk/2022/sessions/coroutines-cpp-vs-rust.html)  
C++ and Rust are both system programming languages that recently received support for asynchronous programming using _coroutines_. Given the memory and perf constraints, both languages opted for _stackless_ coroutines, implemented by a compiler-generated state machine. This is where the similarities stop. Jonathan shows side-by-side comparisons of code using C++/Rust coroutines and highlights the differences. His _conclusions_ are captured in my pictures below.  
I thought C++ had it bad, but Rust coroutines are just as difficult to use/understand 🤷‍♂️   
![](img/sessions/foonathan_1.jpeg)  
![](img/sessions/foonathan_2.jpeg)  
![](img/sessions/foonathan_3.jpeg)  
![](img/sessions/foonathan_4.jpeg)  


### Guy Davidson - [Abstraction: the true superpower of C++](https://cpponsea.uk/2022/sessions/abstraction-the-true-superpower-of-cpp.html)  
"Abstraction" is used extensively when discussing the facilities of C++, particular into the context of the _"zero-cost abstraction"_ mantra.  
But what does it actually mean? Can we spot the correct level of abstraction? Can we correctly identify what is being abstracted? Guy had lots of examples to show us, from simple things to more complex models and APIs that could really benefit from the proper abstraction, if chosen correctly.  
If you want to go deeper into this _and much more_, I highly recommend Guy's new book "Beautiful C++", co-authored with _Kate Gregory_.  
![](img/sessions/guy_1.jpeg)  
![](img/sessions/guy_2.jpeg)  


### Amir Kirsh - [Six ways for implementing max](https://cpponsea.uk/2022/sessions/six-ways-for-implementing-max-a-walk-through-api-design-dangling-references-and-cpp20-constraints.html)  
Six+ ways of implementing `max`: a walk through API design, dangling references and C++20 constraints. From simple requirements to progressively increasing complexity due to the various ways in which C++ can express value types and all kinds of references. This session was an hour long demo.     
What I liked most about this session is it was _highly interactive_. Although Amir had a clear plan in mind, he welcomed/requested input from the audience and folks kept shouting suggestions on what to write next. It felt a bit like [mob programming](https://en.wikipedia.org/wiki/Mob_programming) 😄. The fact that Amir is an experienced teacher (UNI) really shows in how he directed the audience down the right design path.  
![](img/sessions/amir_1.jpeg)  

