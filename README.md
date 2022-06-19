# UsaminJs

JavaScript generator based on RapidJSON.

## Installation

Install RapidJSON beforehand. Only header files are necessary, and no need to build.

Next, add this line to your application's Gemfile:

```ruby
gem 'usamin-js'
```

And then execute:

    $ bundle

Or install it yourself as:

    $ gem install usamin-js

The directory of RapidJSON can be explicitly specified with `--with-rapidjson-dir` option.

    $ gem install usamin-js -- --with-rapidjson-dir=/usr/local/opt/rapidjson

## Usage

```ruby
require 'usamin/js'

puts Usamin::Js.generate({ abe: 'nana', time: Time.now, "3": 5 })
#=> {"abe":"nana","time":new Date(1655617665882),"3":5}
```

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/Ishotihadus/usamin-js.

## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT) at the request of RapidJSON.
